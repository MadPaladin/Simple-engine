#pragma once
#include"SFML/Graphics.hpp"

class Bob
{
private:
	//Player position
	sf::Vector2f m_Position;

	//Sprite
	sf::Sprite m_Sprite;

	//Texture
	sf::Texture m_Texture;

	//Directions where player is moving
	bool m_LeftPressed;
	bool m_RightPressed;

	//Bob's speed in pixels per seconds
	float m_Speed;

public:
	//Bob constructor
	Bob();
	//Send a copy of the sprite to main
	sf::Sprite getSprite();

	//Move Bob in a specific direction
	void moveLeft();

	void moveRight();

	//Stop Bob form moving if no button is pressed
	void stopLeft();

	void stopRight();

	//Update function, it will be called once every frame
	void update(float elapsedTime);
	~Bob();
};


