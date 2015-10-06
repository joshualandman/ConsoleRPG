#include <iostream>
#include "DisplayWorld.h"

using namespace std;

void main()
{
	DisplayWorld world;
	world.ReadFile();
	world.PrintMap();
}