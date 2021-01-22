#pragma once
#include "CObject.h"



class CMoving_object : public CObject
{
protected:
	float speed;

public:

	/**
	* @brief Konstruktor
	*/
	CMoving_object();
	/**
	* @brief Destruktor wirtualny
	*/
	virtual ~CMoving_object();

	/**
	* @brief Wirtualna metoda rysujaca
	* @param target Wskaznik do obiektu gdzie ma byc narysowany obiekt
	*/
	virtual void move(sf::RenderTarget* target);


	
	

};



