#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>


class CButton
{
private:

	

	sf::RectangleShape shape;
	sf::Font* font;
	

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;
	const int textSize = 30;


public:

	enum button_state { IDLE_BTN = 0, HOVER_BTN, PRESSED_BTN };
	short unsigned buttonState;

	CButton(float x, float y, float width, float height, 
		sf::Font* font, std::string text, 
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	~CButton();


	sf::Text text;


	//FUNCTIONS
	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);
	bool isPressed();




};

