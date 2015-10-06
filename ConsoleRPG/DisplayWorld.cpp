#include <iostream>
#include <fstream>
#include "DisplayWorld.h"

using namespace std;

void DisplayWorld::ReadFile()
{
	ifstream myfile("map.txt");
	if (myfile.is_open())
	{
		myfile.get(tile);
		map[y][x] = tile;
		x++;
		while (tile != END)
		{
			// cout << tile;
			myfile.get(tile);
			
			switch (tile)
			{
				case 'x':
					tile = (char)178;
					break;
				case 'd':
					tile = (char)176;
					break;
				case '\n':
					continue;
				default:
					break;
			}
			map[y][x] = tile;

			if (x > 8)
			{
				x = 0;
				y++;
			}
			else
			{
				x++;
			}			
			
		}
		cout << endl;
	}
}

void DisplayWorld::PrintMap()
{
	for (int row = 0; row < rowSize; row++)
	{
		for (int col = 0; col < colSize; col++)
		{
			cout << map[row][col];
		}
		cout << endl;
	}
}

DisplayWorld::DisplayWorld()
{
}


DisplayWorld::~DisplayWorld()
{
}
