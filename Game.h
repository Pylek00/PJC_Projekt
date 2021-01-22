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
	
private:

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
	CMoving_object* m_object;
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

	int ammountOfStartAgents;//liczba agentow na poczatku gry
	int addAgentTime;// odstep czasowy pomiedzy kolejnymi momentami dodania nowych agentow
	int changeDirTime;//odstep czasowy pomiedzy kolejnymi zmianami kierunku poruszania sie agentow
	bool pause;
public:

	//Initialization

	/**
	* @brief Funkcja inicjalizujaca okno programu
	*/
	void initWindow();

	//Constructor/Disctructor
	
	/**
	* @brief Konstruktor
	*/
	Game();
	/**
	* @brief Destruktor
	*/
	virtual ~Game();

	//Functions

	/**
	* @brief Funkcja srawdzajaca ilosc klatek na sekunde
	*/
	void dtFrameTime();
	/**
	* @brief Funkcja aktualizujaca czas trwania rozgrywki
	*/
	void timeUpdate();
	/**
	* @brief Metoda rysujaca tekst na ekranie
	*/
	void renderScreenText(sf::Text screenText);
	/**
	* @brief Metoda inicjalizujaca tekst na ekranie
	*/
	void initScreenText(float x, float y, std::string text, int size);
	/**
	* @brief Metoda inicjalizujaca ekran ladowania
	*/
	void initLoadingScreen();
	/**
	* @brief Metoda rysujaca ekran ladowania
	*/
	void renderLoadingScreen();
	/**
	* @brief Metoda uaktualniajaca stan agentow
	*/
	void updateAgents();
	/**
	* @brief Metoda sprawdzajaca kolizje z agentami
	*/
	void checkAgentCollision();


	/**
	* @brief Metoda uaktualniajaca interakcje uzytkownika
	*/
	void updateSFMLEvents();
	/**
	* @brief Metoda uaktualniajaca pozycje myszy
	*/
	void updateMousePos();
	/**
	* @brief Metoda uaktualniajaca poruszanie sie uzytkownika
	*/
	void updatePlayerMove();
	/**
	* @brief Metoda uaktualniajaca wszytkie wydarzenia w petli gry
	*/
	void update();
	/**
	* @brief Metoda rysujaca wszystkie obiekty w petli gry
	*/
	void render();

	
	/**
	* @brief Metoda rozpoczynajaca program
	*/
	void run();

};


