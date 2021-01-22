#include "CGPlayer.h"




CGPlayer::CGPlayer(CPlayer* object)
{
	
	this->shape.setFillColor(sf::Color::Blue);
	this->shape.setRadius(object->getSize());
	this->shape.setPosition(object->getPosition().x, object->getPosition().y);
	this->shape.setOrigin(sf::Vector2f(object->getSize(), object->getSize()));
	this->player = object;
	
}

CGPlayer::~CGPlayer()
{
	
}


void CGPlayer::update_render(CPlayer* object, sf::RenderTarget *target)
{
	this->shape.setPosition(object->getPosition().x, object->getPosition().y);
	target->draw(this->shape);
}
