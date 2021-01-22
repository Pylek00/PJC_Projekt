#pragma once
#include "CGObject.h"
#include "CPlayer.h"

class CGPlayer : public CGObject
{
public:

	/**
	* @brief Konstruktor
	* @param Wskaznik do obiektu logicznego
	*/
	CGPlayer(CPlayer* object);
	/**
	* @brief Destruktor
	*/
	~CGPlayer();


	/**
	* @brief Funkcja aktualizujaca oraz rysujaca obiekt w oknie
	* @param object Wskaznik do rysowaneg obiektu
	* @param target Wskaznik do obiektu na ktorym bedzie rysowany obiekt
	*/
	void update_render(CPlayer* object, sf::RenderTarget *target);

private:
	CPlayer* player;
	CircleShape shape;
};

