#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class CGObject 
{
public:
	sf::Sprite sprite;
	sf::Texture texture;

	CGObject();
	~CGObject();

	void draw(sf::RenderTarget*target);
};

