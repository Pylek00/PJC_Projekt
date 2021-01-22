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
    /**
    * @brief Wskaznik do obiektu agenta
    */
    CAgent* agent;

    CGAgent(CAgent* object);
    ~CGAgent();
    /**
    * @brief Funkcja uaktualniajaca dane o obiekcie
    * @param object Wskaznik do obiektu
    */
    void update(CAgent* object);
    /**
    * @brief Funkcja renderujaca obiekt w oknie gry
    * @param target Wskaznik do okna gry
    */
    void render(sf::RenderTarget* target);

};

