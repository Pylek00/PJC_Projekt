#pragma once
#include "CGObject.h"
#include "CStone.h"
class CGStone :
    public CGObject
{

public:
    
    /**
    * @brief Konstruktor
    * @param stone Wskaznik do obiektu logicznego
    */
    CGStone(CStone* stone);
    /**
	* @brief Destruktor
	*/
    ~CGStone();


    /**
    * @brief Metoda rysujaca obiekt
    * @param target Docelowe miejsce rysowania obiektu
    */
    void render(RenderTarget* target);

private:
    CStone* stone;
    //sf::RectangleShape shape;

protected:

};

