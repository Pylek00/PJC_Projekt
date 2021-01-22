#pragma once
#include "CObject.h"

class CGrass :
    public CObject
{
public:
    /**
     * @brief Konstruktor
     */
    CGrass(float x, float y,float size);

private:
    bool can_step;
protected:

};

