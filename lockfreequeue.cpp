#include <atomic>
#include <thread>
#include <iostream>

// Lock-Free Single-Producer Single-Consumer Queue
template<typename T>
class LockFreeQueue {
private:
    struct Node {
        T data;
        std::atomic<Node*> next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    std::atomic<Node*> head;
    std::atomic<Node*> tail;

public:
    LockFreeQueue() {
        Node* dummy = new Node(T());
        head.store(dummy);
        tail.store(dummy);
    }

    ~LockFreeQueue() {
        while (Node* old_head = head.load()) {
            head.store(old_head->next);
            delete old_head;
        }
    }

    void Produce(const T& value) {
        Node* new_node = new Node(value);
        Node* old_tail = tail.exchange(new_node);
        old_tail->next.store(new_node);
    }

    bool Consume(T& result) {
        Node* old_head = head.load();
        Node* next = old_head->next.load();
        if (next == nullptr) {
            return false;  // Queue empty
        }
        result = next->data;
        head.store(next);
        delete old_head;
        return true;
    }
};

// Test program
int main() {
    LockFreeQueue<int> queue;
    int consumed_value = 0;

    // Producer thread
    std::thread producer([&]() {
        for (int i = 0; i < 10; ++i) {
            queue.Produce(i);
            std::cout << "Produced: " << i << std::endl;
        }
    });

    // Consumer thread
    std::thread consumer([&]() {
        int count = 0;
        while (count < 10) {
            if (queue.Consume(consumed_value)) {
                std::cout << "Consumed: " << consumed_value << std::endl;
                ++count;
            }
            // Optional small sleep to avoid busy waiting
            std::this_thread::yield();
        }
    });

    producer.join();
    consumer.join();

    return 0;
}
