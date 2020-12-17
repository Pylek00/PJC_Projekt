#include "CGStone.h"

CGStone::CGStone(CStone* stone)
{
	this->stone = stone;
	this->texture.loadFromFile("Textures/rocks.png", sf::IntRect(10, 10, this->stone->size, this->stone->size));
	this->sprite.setOrigin(32, 32);
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(this->stone->position_x, this->stone->position_y);
}

void CGStone::render(RenderTarget* target)
{
	target->draw(this->sprite);
}
