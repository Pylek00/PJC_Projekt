#include "CGPlayer.h"




CGPlayer::CGPlayer(CPlayer* object)
{
	
	this->shape.setFillColor(sf::Color::Blue);
	this->shape.setRadius(object->size);
	this->shape.setPosition(object->position_x, object->position_y);
	this->shape.setOrigin(sf::Vector2f(object->size, object->size));
	this->player = object;
	
}

void CGPlayer::update_render(CPlayer* object, sf::RenderTarget *target)
{
	this->shape.setPosition(object->position_x, object->position_y);
	target->draw(this->shape);
}
