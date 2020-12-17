#include "CMap.h"


CMap::CMap()
{
	
	this->height = 28;
	this->width = 15;
	

}

CMap::~CMap()
{
	for (int i = 0; i < map_g.size(); i++)
	{
		
		delete this->map_g[i];
		delete this->map_o[i];
		
	}
	this->map_g.clear();
	this->map_o.clear();

	delete this->pomGObj;
	delete this->pomGrass;
	delete this->pomStone;
}




void CMap::createRandomMap()
{
	int los;
	

	

	srand(time(NULL));
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			los = rand() % 100 + 1;

			if (los<85)
			{
				this->typ = GRASS;    //grass
			}
			else if(los>=85)
			{
				this->typ = STONE;    //stone
			}
			if ((j>=6 && j <=8) && (i>=12 && i <= 15))
			{
				this->typ = GRASS;
			}

			
			if (typ == GRASS)
			{
				this->pomGrass = new CGrass(i * 64 + 32, j * 64 + 32, 0);
				this->pomGObj = new CGGrass(this->pomGrass);

				this->map_o.push_back(this->pomGrass);
				this->map_g.push_back(this->pomGObj);
			}
			else if (typ == STONE)
			{
				this->pomGrass = new CGrass(i * 64+32, j * 64+32, 0);
				this->pomGObj = new CGGrass(this->pomGrass);

				this->map_o.push_back(this->pomGrass);
				this->map_g.push_back(this->pomGObj);

				this->pomStone = new CStone(i * 64 + 32, j * 64 + 32, 0);
				this->pomGObj = new CGStone(this->pomStone);

				this->map_o.push_back(this->pomStone);
				this->map_g.push_back(this->pomGObj);
			}

			

		}

	}
	
	
	
}

void CMap::render(RenderTarget* target)
{
	for (int i = 0; i < map_g.size(); i++)
	{
		target->draw(map_g[i]->sprite);
	}
	

}






