#include "pch.h"
#include "Bob.h"


Bob::Bob()
{
	//speed of Bob's movement
	m_Speed = 300;

	//Associate a texture with the sprite
	m_Texture.loadFromFile("bob.png");
	m_Sprite.setTexture(m_Texture);

	//Set Bob's starting position
	m_Position.x = 300;
	m_Position.y = 550;
}

sf::Sprite Bob::getSprite()
{
	return m_Sprite;
}

void Bob::moveLeft()
{
	m_LeftPressed = true;
}

void Bob::moveRight()
{
	m_RightPressed = true;
}

void Bob::stopLeft()
{
	m_LeftPressed = false;
}

void Bob::stopRight()
{
	m_RightPressed = false;
}

//Move Bob based on the input this frame,
//tge time elapsed, and the speed

void Bob::update(float elapsedTime)
{
	if (m_RightPressed)
	{
		m_Position.x += m_Speed * elapsedTime;
	}
	if (m_LeftPressed)
	{
		m_Position.x -= m_Speed * elapsedTime;
	}

	m_Sprite.setPosition(m_Position);
}

Bob::~Bob()
{
}
