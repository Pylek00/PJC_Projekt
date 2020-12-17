#pragma once
#include "CMoving_object.h"


class CPlayer : public CMoving_object
{
public: 
	std::string name;

	void setName(std::string Name);

	void setPos(float x, float y);


	CPlayer(float Size, float Speed);
	~CPlayer();

	void move();

private:
	void setSpeed(float Speed);

	void setSize(float Size);

	
protected:

};

