#pragma once
#include "CMoving_object.h"
#include"CPlayer.h"
#include<math.h>

enum directions{N = 0,NE,E,SE,S,SW,W,NW};

class CAgent :
    public CMoving_object
{
public:

    

    /**
    * @brief Konstruktor klasy CAgent
    */
    CAgent(sf::RenderTarget* target);
    /**
    * @brief Destruktor klasy CAgent
    */
    ~CAgent();

    /**
    * @brief Funkcja odpowiedzialna za poruszanie sie agenta
    * @param target Okno, na ktorym wyswietlamy rozgrywke
    */
    void move(sf::RenderTarget* target);
    /**
    * @brief Funkcja sprawdzajaca czy gracz jest w zasiegu wzroku
    * @param player wskaznik do obiektu w zasiegu
    * @return Prawda jezeli znajduje sie w zasiegu
    */
    bool checkIfInRange(CPlayer* player);

    /**
    * @brief Funkcja definiujaca kierunek poruszania sie agenta
    * @param player wskaznik do obiektu w zasiegu
    */
    void setDir();
    /**
    * @brief Funkcja zmieniajaca wartosc predkosc
    * @param speed Predkosc obiektu
    */
    void setSpeed(int speed);
    /**
    * @brief Funkcja pobierajaca wartosc predkosc
    * @return Zwraca predkosc obiektu
    */
    int getSpeed();
    /**
    * @brief Funkcja zmieniajaca wartosc rozmiaru obiektu
    * @param size Predkosc obiektu
    */
    void setSize(int size);
    /**
    * @brief Funkcja pobierajaca rozmiar obiektu
    * @return Zwraca rozmiar obiektu
    */
    int getSize();
    /**
    * @brief Funkcja zmieniajaca zasieg wzroku
    * @param seeRange Predkosc obiektu
    */
    void setSeeRange(int seeRange);
    /**
    * @brief Funkcja pobierajaca zasieg wzroku
    * @return Zwraca zasieg wzroku
    */
    int getSeeRange();
    /**
    * @brief Funkcja zmieniajaca poczatkowa pozycje obiektu
    * @param target Okno gry
    */
    void setPos(sf::RenderTarget* target);
    /**
    * @brief Funkcja zwracajaca pozycje obiektu
    * @return Zwraca wektor pozycji x oraz y
    */
    sf::Vector2f getPos();

private:
    int seeRange;
    directions dir;
    int moveDir;
    sf::Vector2u vector;
    
protected:

};

