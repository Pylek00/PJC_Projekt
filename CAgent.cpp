#include "CAgent.h"

void CAgent::setSpeed(int speed)
{
	if (speed > 0)
		this->speed = speed;
	else
		this->speed = 10;
}

void CAgent::setSize(int size)
{
	if (size > 5)
		this->size = size;
	else
		this->size = 10;
}

void CAgent::setSeeRange(int seeRange)
{
	if (size < 5)
		this->seeRange = size*10;
	else
		this->seeRange = seeRange;
}

void CAgent::setPos(sf::RenderTarget* target)
{

	
	this->vector = target->getSize();
	float angle;
	
	angle = rand() % 360 +1;
	

	if (angle > 0 && angle <= 90 )
	{
		this->position_x = angle/90* this->vector.x;
		this->position_y = this->size;
	}
	else if(angle > 90 && angle <= 180)
	{
		this->position_x = this->vector.x - this->size;
		this->position_y = (angle-90)/90* this->vector.y;
	}
	else if (angle > 180 && angle <= 270)
	{
		this->position_x = (angle-180)/90 * this->vector.x;
		this->position_y = this->vector.y-this->size;
	}
	else if (angle > 270 && angle <= 360)
	{
		this->position_x = this->size;
		this->position_y = (angle-270)/90 * this->vector.y;
	}
	

}

CAgent::CAgent(sf::RenderTarget* target)
{
	

	
	this->setDir();
	this->setSize(7);
	this->setSpeed(rand()%10+5);
	this->setSeeRange(rand() % 40 + 60);
	this->setPos(target);
}

CAgent::~CAgent()
{
}

void CAgent::move(sf::RenderTarget* target)
{
	
	switch (this->moveDir)
	{
	case N:  {this->position_y -= this->speed;                                  if (position_y < 0)              { this->moveDir = S; }                                                         break; }
	//case N: {this->position_y -= this->speed; this->position_x += this->speed; if (position_y < 0) { this->moveDir = SE; } if (position_x > this->vector.x) { this->moveDir = NW; } break; }
	case NE: {this->position_y -= this->speed; this->position_x += this->speed; if (position_y < 0)              { this->moveDir = SE;} if (position_x > this->vector.x) { this->moveDir = NW;} break; }
	case E:  {                                 this->position_x += this->speed; if (position_x > this->vector.x) { this->moveDir = W; }                                                         break; }
	//case E: {this->position_y += this->speed; this->position_x += this->speed; if (position_y > this->vector.y) { this->moveDir = NE; } if (position_x > this->vector.x) { this->moveDir = SW; } break; }
	case SE: {this->position_y += this->speed; this->position_x += this->speed; if (position_y > this->vector.y) { this->moveDir = NE;} if (position_x > this->vector.x) { this->moveDir = SW;} break; }
	case S:  {this->position_y += this->speed;                                  if (position_y > this->vector.y) { this->moveDir = N; }                                                         break; }
	//case S: {this->position_y += this->speed; this->position_x -= this->speed; if (position_y > this->vector.y) { this->moveDir = NW; } if (position_x < 0) { this->moveDir = SE; } break; }
	case SW: {this->position_y += this->speed; this->position_x -= this->speed; if (position_y > this->vector.y) { this->moveDir = NW;} if (position_x < 0)              { this->moveDir = SE;} break; }
	case W:  {                                 this->position_x -= this->speed; if (position_x < 0)              { this->moveDir = E; }                                                         break; }
	//case W: {this->position_y -= this->speed; this->position_x -= this->speed; if (position_y < 0) { this->moveDir = SW; } if (position_x < 0) { this->moveDir = NE; } break; }
	case NW: {this->position_y -= this->speed; this->position_x -= this->speed; if (position_y < 0)              { this->moveDir = SW;} if (position_x < 0)              { this->moveDir = NE;} break; }
	}
}

bool CAgent::checkIfInRange(CPlayer* player)
{
	float distance;
	distance = sqrt(pow(player->position_x - this->position_x,2) + pow(player->position_y - this->position_y,2));
	if (distance < this->seeRange)
	{
		return true;
	}
	else
		return false;
}

void CAgent::setDir()
{
	
	this->moveDir = rand() % 8;
}
