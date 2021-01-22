#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <random>
#include <windows.h>
#include <cstdlib>
#include <time.h>


using namespace sf;

class CObject
{
protected:
	float size;

	float position_x;
	float position_y;

public:

	/**
	* @brief Metoda ustawiajaca pozycje obiektu
	* @param x Wspolrzedna x
	* @param y Wspolrzedna y
	*/
	void setPosition(float x, float y);
	/**
	* @brief Metoda pobierajaca pozycje obiektu
	* @return Zwraca wektor wzpolrzednych x oraz y
	*/
	sf::Vector2f getPosition();
	/**
	* @brief Metoda pobierajaca informacje o rozmiarze
	* @return Rozmiar obiektu
	*/
	float getSize();
	/**
	* @brief Metoda ustawiajaca rozmiar
	* @param s Rozmiar
	*/
	void  setSize(int s);

	/**
	* @brief Konstruktor
	*/
	CObject();
	/**
	* @brief Destuktor
	*/
	virtual ~CObject();
	
	
};

