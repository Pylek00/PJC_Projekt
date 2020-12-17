#pragma once
#include "CGObject.h"
#include "CPlayer.h"

class CGPlayer : public CGObject
{
public:

	CPlayer* player;
	CircleShape shape;

	CGPlayer(CPlayer* object);

	void update_render(CPlayer* object, sf::RenderTarget *target);


};

