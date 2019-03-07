#include "pch.h"
#include "Engine.h"


Engine::Engine()
{
	//Get the window screen resolution and create an SFML window and view
	sf::Vector2f resolution;
	resolution.x = sf::VideoMode::getDesktopMode().width;
	resolution.y = sf::VideoMode::getDesktopMode().height;

	m_Window.create(sf::VideoMode(1024, 768),
		"Simple game engine",
		sf::Style::Fullscreen);

	//Load the background into the texture
	//Scale this image to your screen size
	m_BackgroundTexture.loadFromFile("forest2.png");

	//associate sprite with the texture
	m_BackgroundSprite.setTexture(m_BackgroundTexture);
}

void Engine::input()
{
	//Handle the player quitting
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		m_Window.close();
	}

	//Handle the player moving
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_Bob.moveLeft();
	}
	else
	{
		m_Bob.stopLeft();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_Bob.moveRight();
	}
	else
	{
		m_Bob.stopRight();
	}
}

void Engine::update(float dtAsSeconds)
{
	m_Bob.update(dtAsSeconds);
}

void Engine::draw()
{
	//Rub out the last frame
	m_Window.clear(sf::Color::White);

	//Draw the background
	m_Window.draw(m_BackgroundSprite);
	m_Window.draw(m_Bob.getSprite());

	//Display everything we have drawn
	m_Window.display();
}

void Engine::start()
{
	//timing
	sf::Clock clock;
	while (m_Window.isOpen())
	{
		//Restart the clock and save the elapsed time into deltaTime
		sf::Time dt = clock.restart();

		//Make a fraction from delta time
		float dtAsSeconds = dt.asSeconds();

		input();
		update(dtAsSeconds);
		draw();
	}
}


Engine::~Engine()
{
}
