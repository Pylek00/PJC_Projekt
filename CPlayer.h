#pragma once
#include "CMoving_object.h"


class CPlayer : public CMoving_object
{
public: 
	
	/**
	* @brief Metoda wprowadzajaca nazwe gracza
	* @param Name Nazwa gracza
	*/
	void setName(std::string Name);

	/**
	* @brief Metoda ustawiajaca pozycje startowa gracza
	* @param x Pozycja x
	* @param y Pozycja y
	*/
	void setStartPos(float x, float y);

	/**
	* @brief Konstruktor
	* @param Size Rozmiar obiektu
	* @param Speed Predkosc obiektu
	*/
	CPlayer(float Size, float Speed);
	/**
	* @brief Destruktor
	*/
	~CPlayer();

	/**
	* @brief Funkcja poruszania obiektu
	* @param target Docelowe miejsce poruszania sie obiektu
	*/
	void move(sf::RenderTarget* target);

private:

	std::string name;
	sf::Vector2u vector;

	/**
	* @brief Metoda ustawiajaca predkosc
	* @param Speed Predkosc
	*/
	void setSpeed(float Speed);
	/**
	* @brief Metoda ustawiajaca rozmiar
	* @param Size Rozmiar
	*/
	void setSize(float Size);

	
protected:

};

