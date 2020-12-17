#include "CGGrass.h"

CGGrass::CGGrass(CGrass* grass)
{
	this->grass = grass;
	this->texture.loadFromFile("Textures/grass2.jpg", sf::IntRect(10,10,this->grass->size,this->grass->size));	
	this->sprite.setOrigin(32, 32);
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(this->grass->position_x, this->grass->position_y);
	
}

void CGGrass::render(RenderTarget* target)
{
	target->draw(this->sprite);
}

