#pragma once
#include "CGObject.h"
#include "CStone.h"
class CGStone :
    public CGObject
{

public:
    CStone* stone;

    CGStone(CStone* stone);

    void render(RenderTarget* target);

private:

    //sf::RectangleShape shape;

protected:

};

