#ifndef ENGINE
#define ENGINE
#include "SFML/Graphics.hpp"
#include "Bob.h"

class Engine
{
private:
	//Render window
	sf::RenderWindow m_Window;
	
	//Declare a sprote and a Texture for the background
	sf::Sprite m_BackgroundSprite;
	sf::Texture m_BackgroundTexture;

	//An instance of Bob
	Bob m_Bob;

	//Private functions fo internal use only
	void input();
	void update(float dtAsSeconds);
	void draw();
public:
	//Default constructor
	Engine();

	//start will call all the private functions
	void start();

	~Engine();
};
#endif //engine
