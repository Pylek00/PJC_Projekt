#include "CGAgent.h"

CGAgent::CGAgent(CAgent* object)
{

	this->shape.setFillColor(sf::Color::Red);
	this->shape.setRadius(object->getSize());
	this->shape.setPosition(object->position_x, object->position_y);
	this->shape.setOrigin(sf::Vector2f(object->getSize(), object->getSize()));
	this->agent = object;

	this->range.setFillColor(sf::Color(255,255,255,50));
	this->range.setRadius(object->getSeeRange());
	this->range.setPosition(object->position_x, object->position_y);
	this->range.setOrigin(sf::Vector2f(object->getSeeRange(), object->getSeeRange()));

}

CGAgent::~CGAgent()
{
	
}
  
void CGAgent::update(CAgent* object)
{
	this->shape.setPosition(object->position_x, object->position_y);
	this->range.setPosition(object->position_x, object->position_y);
	
}

void CGAgent::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	target->draw(this->range);
}
