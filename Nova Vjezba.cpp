#include "pch.h"
#include <iostream>
#include "Engine.h"
#include "SFML/Graphics.hpp"
using namespace std;

int main()      
{  
	//Declare an engine instance
	Engine engine;
	//Start the engine
	engine.start();

	//Quit in the usual way when the engine is stopped
	return 0;
}


