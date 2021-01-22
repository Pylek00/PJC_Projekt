#pragma once
#include "CObject.h"
class CStone :
    public CObject
{
public:
    
    /**
    * @brief Konstruktor
    * @param x Wspolrzedna x
    * @param y Wspolrzedna y
    * @param size Rozmiar
    */
    CStone(float x, float y, float size);

private:

    bool can_step;

protected:



};

