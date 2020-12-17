#pragma once
#include "CMoving_object.h"
#include"CPlayer.h"
#include<math.h>

enum directions{N = 0,NE,E,SE,S,SW,W,NW};

class CAgent :
    public CMoving_object
{
public:

    int seeRange;
    directions dir;
    int moveDir;
    sf::Vector2u vector;

    CAgent(sf::RenderTarget* target);
    ~CAgent();

    void move(sf::RenderTarget* target);
    bool checkIfInRange(CPlayer* player);
    void setDir();
    

private:
    void setSpeed(int speed);
    void setSize(int size);
    void setSeeRange(int seeRange);
    void setPos(sf::RenderTarget* target);
    
protected:

};

