#include "CObject.h"

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
