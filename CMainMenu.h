#pragma once
#include<SFML/Graphics.hpp>

#include"CButton.h"

class CMainMenu
{
private:
	sf::Texture texture;
	
	sf::Font font;


	int width;
	int height;

	sf::Sprite sprite;
	sf::Text text;
public:
	
	/**
	* @brief Konstruktor
	*/
	CMainMenu();
	/**
	* @brief Destruktor
	*/
	~CMainMenu();
	
	/**
	* @brief Wskaznik do przycisku start game
	*/
	CButton* startGameBTN;
	/**
	* @brief Wskaznik do przycisku exit game
	*/
	CButton* exitGameBTN;
	/**
	* @brief Wskaznik do przycisku options
	*/
	CButton* optionsGameBTN;

	/**
	* @brief Metoda inicjujaca menu glowne
	* @param window Okno gdzie wyswietlane jest menu glowne
	*/
	void initMainMenu(sf::RenderWindow* window);
	
};

