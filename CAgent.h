#pragma once
#include "CMoving_object.h"
#include"CPlayer.h"
#include<math.h>

enum directions{N = 0,NE,E,SE,S,SW,W,NW};

class CAgent :
    public CMoving_object
{
public:

    
    directions dir;
    int moveDir;
    sf::Vector2u vector;

    CAgent(sf::RenderTarget* target);
    ~CAgent();

    void move(sf::RenderTarget* target);
    bool checkIfInRange(CPlayer* player);
    void setDir();
    
    void setSpeed(int speed);
    int getSpeed();
    void setSize(int size);
    int getSize();
    void setSeeRange(int seeRange);
    int getSeeRange();
    void setPos(sf::RenderTarget* target);
    sf::Vector2i getPos();

private:
    int seeRange;
    
protected:

};

