#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class CGObject 
{
public:

	/**
	* @brief Konstruktor
	*/
	CGObject();
	/**
	* @brief Destruktor
	*/
	~CGObject();

	/**
	* @brief Funkcja rysujaca obiekt
	* @param target Wskaznik do obiektu gdzie ma byc narysowany obiekt
	*/
	void draw(sf::RenderTarget*target);

	/**
	* @brief Sprite
	*/
	sf::Sprite sprite;
	/**
	* @brief Tekstura
	*/
	sf::Texture texture;
};

