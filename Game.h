#pragma once

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>
#include<fstream>
#include<stack>
#include<random>


#include"CPlayer.h"
#include"CGPlayer.h"

#include"CAgent.h"
#include"CGAgent.h"

#include"CGGrass.h"
#include"CGGrass.h"

#include"CGStone.h"
#include"CGStone.h"

#include"CButton.h"
#include"CMainMenu.h"
#include"CMap.h"



#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

class Game
{
private:
	class Settings
	{






	};
public:
	//Variables

	sf::Window* wind;
	sf::Event SFevent;
	sf::VideoMode window_bounds;
	sf::RenderWindow* window;
	sf::ContextSettings settings;
	sf::View view;
	

	sf::Font font;
	sf::Font screenFont;
	CButton* startGameBTN;

	enum game_window_state { MAIN_MENU = 0, GAME_OPTIONS, PLAY_GAME, EXIT ,};
	unsigned short gameWindowState;

	
	CPlayer* player;
	CGPlayer* gplayer;
	CMap* map;


	//agents variables
	std::vector<CGAgent*>  agents_g;
	std::vector<CAgent*>   agents_o;
	CAgent* pomAgent;
	CGAgent* pomGAgent;


	sf::RectangleShape loadingScreen;
	sf::Text screenText;
	

	float dt;
	sf::Clock dtTime;

	sf::Clock gameTime;
	float time;
	Vector2f mousePosView;

	int ammountOfStartAgents;
	int addAgentTime;
	int changeDirTime;
	//Initialization
	void initWindow();


	//Constructor/Disctructor
	
	Game();
	virtual ~Game();

	//Functions


	void dtFrameTime();
	void timeUpdate();
	void renderScreenText(sf::Text screenText);

	void initScreenText(float x, float y, std::string text, int size);

	void initLoadingScreen();
	void renderLoadingScreen();

	void updateAgents();
	void checkAgentCollision();

	void updateSFMLEvents();
	void updateMousePos();
	void updatePlayerMove();
	void update();
	void render();
	void run();

};


