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
public:

	float position_x;
	float position_y;



	float getSize();
	void  setSize(int s);


	CObject();
	virtual ~CObject();
	
	
};

