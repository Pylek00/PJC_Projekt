#include "CObject.h"

void CObject::setPosition(float x, float y)
{
	this->position_x = x;
	this->position_y = y;
}

sf::Vector2f CObject::getPosition()
{
	return sf::Vector2f(this->position_x,this->position_y);
}

float CObject::getSize()
{
	return this->size;
}

void CObject::setSize(int s)
{
	if (s >= 5)
		this->size = s;
	else
		this->size = 5;
}

CObject::CObject()
{
	this->position_x = 400;
	this->position_y = 600;
	this->setSize(10);
}

CObject::~CObject()
{
}
