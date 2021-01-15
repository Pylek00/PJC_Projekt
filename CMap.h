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

	std::vector<CGObject*>  map_g;
	std::vector<CObject*>  map_o;

	CGrass* pomGrass;
	CStone* pomStone;
	
	CGObject* pomGObj;
	numObj typ;

	CMap();
	~CMap();

	void createRandomMap();
	void render(RenderTarget* target);


private:
	int height;
	int width;
protected:

};

