/*!
\file main.cpp
\brief Contains the entry point for the application
*/

#include <Box2D/Box2D.h>

#include <SFML/Graphics.hpp>

#include "game.h"

void main() /** Entry point for the application */
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Box2D Demo"); // Open main window
	Game game;

	float fFrameTime = 1.f / 60.f;

	// Start a clock to provide time for the physics
	sf::Clock clock;
	//Displays the title at the top of the window
	sf::Font font;

	if (!font.loadFromFile("./assets/font/freshman.ttf"))
	{
		std::cout << "Error failed Loading Font" << std::endl;
		exit(0);
	}
	sf::Text text;
		text.setFont(font);              
		text.setString("PotSumBallz Game");               
		text.setCharacterSize(50);          
		text.setScale(0.01f, 0.01);      
		text.setFillColor(sf::Color::Black); 
		text.setPosition(-2.3f, -2.8f);      

	// Run a game loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// window closed button pressed
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				game.processKeyPress(event.key.code);
			}
		}

		// Find out how much time has elapsed

		float m_fElapsedTime = clock.getElapsedTime().asSeconds();
		// If a frame has past the update the physics
		if (m_fElapsedTime > fFrameTime)
		{
			game.update(m_fElapsedTime);
			clock.restart();
		}

		window.clear(sf::Color::White);
		//draws everything
		window.draw(game);
		window.draw(text);
		window.display();
	}



}