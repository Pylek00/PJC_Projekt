#include "CMainMenu.h"




CMainMenu::CMainMenu()
{
	sf::IntRect rect(0, 0, 1280, 1000);
	this->texture.loadFromFile("Textures/MainMenu.jpg", rect);
	this->font.loadFromFile("Textures/28 Days Later.ttf");
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(0, 0);
	this->sprite.setTextureRect(rect);
	this->sprite.setScale(sf::Vector2f(1.41, 1));
	this->width = rect.width;
	this->height = rect.height;
	this->sprite.setTextureRect(rect);
	

	this->text.setString("Angry Agents");
	this->text.setFont(this->font);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(150);
	this->text.setPosition(500,0);

	startGameBTN = new CButton(900, 250, 200, 100, &font,
		"Start Game",
		sf::Color(198, 206, 206,200),
		sf::Color(245, 245, 220,200),
		sf::Color(54, 69, 79,200));

	exitGameBTN = new CButton(900, 750, 200, 100, &font,
		"Exit Game",
		sf::Color(198, 206, 206,200),
		sf::Color(245, 245, 220,200),
		sf::Color(54, 69, 79,200));

	optionsGameBTN = new CButton(900, 500, 200, 100, &font,
		"Options",
		sf::Color(198, 206, 206, 200),
		sf::Color(245, 245, 220, 200),
		sf::Color(54, 69, 79, 200));
	

}

CMainMenu::~CMainMenu()
{
	delete exitGameBTN;
	delete startGameBTN;
}


void CMainMenu::initMainMenu(sf::RenderWindow* window)
{
	
	
	window->draw(this->sprite);
	window->draw(this->text);
	
	

}

