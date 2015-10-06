#include <iostream>
#include <fstream>
#include <Windows.h>
#include "DisplayWorld.h"

using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

void DisplayWorld::ReadFile()
{
	// alter colors
	SetConsoleTextAttribute(console, FOREGROUND_GREEN | BACKGROUND_BLUE);

	// read the file
	ifstream myfile("map.txt");
	if (myfile.is_open())
	{
		//get spot one and add it to the grid
		myfile.get(tile);
		map[y][x] = tile;
		x++;

		// while the grid is not empty parse the characters and add to
		// 2D array
		while (tile != END)
		{
			myfile.get(tile);
			
			switch (tile)
			{
				case 'x':
					tile = (char)178;
					break;
				case 'w':
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
