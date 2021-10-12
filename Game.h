#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>


class Game
{
private :
	float speed; //Game speed (you can pick any speed unit you wish) 
	int numBarrels; //Number of barrel objects 
	int numSandbags; //Number of sandbag objects 
	int numPlayers; //Number of player objects 
	int width; //Game screen width 
    int height; //Game screen height 
	sf::RenderWindow* window;//SFML window object 
	sf::Texture bgTexture;//Background tile (grass) texture 
	sf::Sprite bgSprite;//Background tile (grass) sprite 
	Barrel *barrels; //Pointer to barrel objects 
	Sandbag *sandbags;//Pointer to sandbag objects 
	Player* players; //Pointer to player objects 
public:
	Game(float speed, int w, int h, int nb, int ns, int np);
	

	void drawBackground(void) ;
		//Draws game background
	void update() {};
		//Draws all objects and updates screen

};
class Coord
{
public:
	float x;
	float y;
	Coord() {
		x = 0; y = 0;
	};

	Coord(float, float);
};
class Player {
	private;
	sf::Texture textures[14];
	sf::Sprite sprite;
	sf::RenderWindow *window;
	Coord pos;
	int state;
	int s;
public:





};

Game::Game(float speed, int w, int h, int nb, int ns, int np) {
	this->speed = speed;
	this->height = h;
	this->width = w;
	this->numBarrels = nb;
	this->numPlayers = np;
	this->numSandbags = ns;

}

Class Player {
private :
sf::Texture textures[14] //Player texture array (one element per soldier state) 
sf::Sprite sprite //Player sprite 
sf::RenderWindow *window //Pointer to SFML window object 
Coord pos //Position of the player on screen 
int state //Primary state of the player (range 0-13) (see Figure 5) 
int s //Secondary state variable (see Figure 5) 
public :
void init(sf::RenderWindow *window, string textBasePath, int numTextures, Coord pos) :
/*Initializes player object
	Parameters :
 window //SFML window object 
 textBasePath //This is the path to the folder that contains player textures 
 numTextures //Number of player textures (should be 14) 
 pos //Player position void setPosition(Coord pos): */
//Sets player position
bool checkCollision(Barrel *barrels, Sandbag *sandbags, int nb, int ns) :
	Checks whether player collides with one of the other objects
	Parameters :
? barrels //Pointer to barrel objects 
? sandbags //Pointer to sandbag objects 
? nb //Number of barrel objects 
? ns //Number of sandbag objects 
void walk(float speed, WalkDirection dir, Barrel *barrels, Sandbag *sandbags, int nb, int ns) :
	Moves the player around
	Parameters :
? speed //Player move speed (you can pick any speed you unit you wish) 
? dir //One of the WalkDirection enum values (Left, Up, Right, Down) 
? barrels //Pointer to barrel objects 
? nb //Number of barrel objects 
? ns //Number of sandbag objects 
void paint() :
	Draws the player sprite
	4. Sandbag
	Private Members :
sf::RenderWindow* window //SFML window object 
sf::Texture texture //Sandbag texture 
sf::Sprite sprite //Sandbag sprite 
Coord pos; //Sandbag position 
Public Methods :
void init(sf::RenderWindow *window, string texturePath, Coord pos) :
	Initializes sandbag object
	Parameters :
? window //SFML window object 
? texturePath //This is the path to the sandbag texture file 
? pos //Sandbag position 
Coord getPosition() :
	Returns sandbag position
	void paint() :
	Draws the sandbag sprite
	5. Barrel
	Private Members :
sf::RenderWindow* window //SFML window object 
sf::Texture texture //Barrel texture 
sf::Sprite sprite //Barrel sprite 
Coord pos; //Barrel position Public Methods: 
void init(sf::RenderWindow *window, string texturePath, Coord pos) :
	Initializes sandbag object
	Parameters :
? window //SFML window object 
? texturePath //This is the path to the sandbag texture file 
? pos //Sandbag position 
Coord getPosition() :
	Returns barrel position
	void paint() :
	Draws the barrel sprite
