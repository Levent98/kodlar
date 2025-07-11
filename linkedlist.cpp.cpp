//============================================================================
// Name        : selam.cpp
// Author      : lk
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>

class Node {
public:
	int value;
	Node* next;
    Node(int x):value(x){next=nullptr;} // this->value=x;
};
class LinkedList{
private:
	Node* head;
	Node* tail;
	int length;
public:
	LinkedList(int val){ Node* temp = new Node (val); head=temp; tail=temp; length=1;}
    void printLinkedList(){ Node * temp= head; while (temp!=nullptr){ std::cout<<temp->value<<std::endl; temp=temp->next;}}
    ~LinkedList( ){Node* temp= head; while(head){head=head->next; delete temp; temp=head; }}
    void append(int val){ Node * link=new Node (val); tail->next=link; tail=link; length++;}
    void getlength (){ std::cout<<"the length of the linked list is :"<<length<<std::endl;}
    void deletelast(){if(length==0) return ; Node* temp =head; Node *pre=head; while(temp->next){  pre=temp ; temp=temp->next; }
    tail=pre; pre->next=nullptr; length--; if (length==0){head= nullptr; tail=nullptr; } delete temp;}
    void prepend(int val){ Node * node = new Node(val); if (length==0){head=nullptr; tail=nullptr;}node->next=head; head=node; length++;}
    void deletefirst(){Node* temp= head; head=temp->next; length--; delete temp; }
    Node* Get(int index){ if(index>length||index<0) return nullptr; else { Node * temp = head; for(int i=0 ;i<index;i++){
    	temp=temp->next;
    }
    return temp;}}
    bool set (int index ,int val){ Node *temp= Get(index); if (temp){ temp->value=val; return true ; } else return false;}
    bool insert (int index , int val){ if (index==0){ prepend(val); return true;} if (length == index){ append(val); return true;} if(length<0||index>length) return false; else{
    Node*yeni= new Node(val);	Node* temp = Get(index-1); yeni->next=temp->next; temp->next=yeni; return true ;}
    }
    void deleteNode (int index ){if (index<0 ||index >= length) return  ; if (index==0) return deletefirst(); if (index==length-1) return deletelast();
    Node * prev =Get(index-1); Node*temp=prev->next; prev->next=temp->next; length--; delete temp;}

};

template <typename T>
T smallest(const T * ,int n)
{
	if(n ==0) return -1;



}



int main() {

	LinkedList* list=new LinkedList(5);
	list->append(8);
	list->append(15);
	//list->deletelast();
	//list->deletefirst();
	list->prepend(6);
	//list->deletelast();
	//list->deletelast();
	//list->deletelast();
	list->getlength();
	//list->set(2,34);
	list->insert(1,67);
	list->deleteNode(0);
	std::cout<<"this is the node:"<<list->Get(2)->value<<std::endl;
    list->printLinkedList();

	return 0;
}
