#include "CPlayer.h"



void CPlayer::setSpeed(float Speed)
{
	if (Speed > 0)
		this->speed = Speed;
	else
		this->speed = 10;
}

void CPlayer::setSize(float Size)
{
	if (Size > 5)
		this->size = Size;
	else
		this->size = 10;
}

void CPlayer::setPos(float x, float y)
{
	if (x > 0 && y > 0)
	{
		this->position_x = x;
		this->position_y = y;
	}
	else
	{
		this->position_x = this->size;
		this->position_y = this->size;
	}
}

void CPlayer::setName(std::string Name)
{
	std::cout << "What is your name?" << std::endl;
	std::getline(std::cin, Name);
	this->name = Name;

	std::cout << "Wellcome " << this->name << "!\n";
}

CPlayer::CPlayer(float Size, float Speed)
{
	
	
	this->setPos(400, 300);
	this->setSize(Size);
	this->setSpeed(Speed);
}

CPlayer::~CPlayer()
{
}

void CPlayer::move()
{
	//Keyboard input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { this->position_x += this->speed; }
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { this->position_x -= this->speed; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { this->position_y += this->speed; }
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { this->position_y -= this->speed; }
}
