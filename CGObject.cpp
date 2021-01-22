#include "CGObject.h"

CGObject::CGObject()
{

}

CGObject::~CGObject()
{
}

void CGObject::draw(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}


