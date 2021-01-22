#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>


class CButton
{
private:

	sf::Font* font;
	

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;
	const int textSize = 30;

	enum button_state { IDLE_BTN = 0, HOVER_BTN, PRESSED_BTN };
	short unsigned buttonState;

	sf::Text text;
	sf::RectangleShape shape;


public:
	/**
	* @brief Metoda pobierajaca stan przycisku
	* @return Stan przycisku enum
	*/
	int getButtonState();
	/**
	* @brief Metoda ustawiajaca stan przycisku
	* @param Stan przycisku enum
	*/
	void setButtonState(int bState);

	/**
	* @brief Konstruktor
	* @param x Pozycja x przycisku
	* @param y Pozycja y przycisku
	* @param width Szerokosc przycisku
	* @param height Wysokosc przycisku
	* @param font Wskaznik do czcionki
	* @param text Napis
	* @param idleColor Domyslny kolor przycisku
	* @param hoverColor Kolor przycisku po najechaniu na niego myszka
	* @param activeColor Kolor przycisku po jego nacisnieniu
	*/
	CButton(float x, float y, float width, float height, 
		sf::Font* font, std::string text, 
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	/**
	* @brief Destruktor
	*/
	~CButton();


	//FUNCTIONS
	/**
	* @brief Metoda uaktualniajaca stan przycisku
	* @param mousePos Wektor pozycji myszy
	*/
	void update(const sf::Vector2f mousePos);
	/**
	* @brief Metoda rysujaca przycisk
	* @param target Okno w ktorym rysowany jest obiekt
	*/
	void render(sf::RenderTarget* target);
	/**
	* @brief Metoda okreslajaca czy przycisk jest wcisniety
	* @return Prawda jezeli przycisk jest wcisniety
	*/
	bool isPressed();

};

