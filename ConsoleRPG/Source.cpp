#include <iostream>
#include "DisplayWorld.h"
#include "Input.h"

using namespace std;

void main()
{
	Input::InitializeInput();

	DisplayWorld world;
	world.ReadFile();
	world.PrintMap();
}