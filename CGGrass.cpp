#include "CGGrass.h"

CGGrass::CGGrass(CGrass* grass)
{
	this->grass = grass;
	this->texture.loadFromFile("Textures/grass2.jpg", sf::IntRect(10,10,this->grass->getSize(),this->grass->getSize()));
	this->sprite.setOrigin(32, 32);
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(this->grass->getPosition().x, this->grass->getPosition().y);
	
}

CGGrass::~CGGrass()
{
	delete grass;
}

void CGGrass::render(RenderTarget* target)
{
	target->draw(this->sprite);
}

