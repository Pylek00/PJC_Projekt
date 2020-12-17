#pragma once
#include "CGObject.h"
#include"CAgent.h"
#include"SFML/Graphics.hpp"

class CGAgent :
    public CGObject
{

    sf::CircleShape shape;
    sf::CircleShape range;
public:

    CAgent* agent;

    CGAgent(CAgent* object);


    void update(CAgent* object);
    void render(sf::RenderTarget* target);

};

