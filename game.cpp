#include<iostream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include "Game.h"


// using namespace sf

int main() {

	sf::RenderWindow window(sf::VideoMode(800, 600), "My First Game",sf::Style::Titlebar|sf::Style::Close);
	sf::Event ev;

	while (window.isOpen()) {

		while (window.pollEvent(ev)) {

			switch (ev.type) {
			case sf::Event::Closed:
					window.close();
					break;
			case sf::Event::KeyPressed:
				if (ev.key.code == sf::Keyboard::A)
					window.close();
						break;
						
			}

		}
	window.clear(sf::Color::Red);//clear old frame
	window.display();//draw game
	}


	
	
	return 0;
}