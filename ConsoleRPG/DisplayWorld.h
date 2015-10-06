#pragma once
class DisplayWorld
{
public:
	char tile;
	char END = '*';
	int x = 0;
	int y = 0;
	int rowSize = 9;
	int colSize = 9;
	char map[9][9];
	void ReadFile();
	void PrintMap();
	DisplayWorld();
	~DisplayWorld();
};

