#pragma once
#include "CGObject.h"
#include "CGrass.h"

class CGGrass :
    public CGObject
{
public:
    
    /**
    * @brief Konstruktor
    */
    CGGrass(CGrass* grass);
    /**
    * @brief Destruktor
    */
    ~CGGrass();


    /**
    * @brief Funkcja renderujaca obiekt w oknie gry
    * @param target wskaznik do okna gry
    */
    void render(RenderTarget* target);


private:

    CGrass* grass;
    //sf::RectangleShape shape;
    
protected:



};

