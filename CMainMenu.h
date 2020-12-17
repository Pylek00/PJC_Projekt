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

	

public:
	sf::Sprite sprite;
	sf::Text text;
	CMainMenu();
	~CMainMenu();
	CButton* startGameBTN;
	CButton* exitGameBTN;
	CButton* optionsGameBTN;

	void initMainMenu(sf::RenderWindow* window);
	
};

