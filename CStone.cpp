#include "CStone.h"

CStone::CStone(float x, float y, float size)
{
	this->can_step = true;
	this->position_x = x;
	this->position_y = y;
	this->size = 64;
}
