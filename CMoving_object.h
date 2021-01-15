#pragma once
#include "CObject.h"



class CMoving_object : public CObject
{
protected:
	float speed;

public:

	CMoving_object();
	virtual void move(sf::RenderTarget* target);
	virtual ~CMoving_object();

	
	

};



