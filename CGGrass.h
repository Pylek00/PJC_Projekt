#pragma once
#include "CGObject.h"
#include "CGrass.h"

class CGGrass :
    public CGObject
{
public:
    CGrass* grass;

    CGGrass(CGrass* grass);

    ~CGGrass();

    void render(RenderTarget* target);


private:

    //sf::RectangleShape shape;
    
protected:



};

