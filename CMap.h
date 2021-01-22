#pragma once



#include <vector>
#include <random>
#include <fstream>
#include<iostream>
#include <array>

#include"CGrass.h"
#include"CGGrass.h"

#include"CGStone.h"
#include"CStone.h"



class CMap
{

public:

	enum numObj { GRASS = 0, STONE, WATER };

	/**
	* @brief Konstruktor
	*/
	CMap();
	/**
	* @brief Destruktor
	*/
	~CMap();
	/**
	* @brief Metoda tworzaca losowa mape
	*/
	void createRandomMap();
	/**
	* @brief Metoda renderujaca mape
	* @param target Wskaznik do okna gry
	*/
	void render(RenderTarget* target);


private:

	int height;
	int width;
	std::vector<CGObject*>  map_g;
	std::vector<CObject*>  map_o;

	CGrass* pomGrass;
	CStone* pomStone;

	CGObject* pomGObj;
	numObj typ;

protected:

};

