#pragma once

#include "background.h"
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <string>


void Background::setTable()
{
	background.loadFromFile("./assets/Textures//Table.png");// loads the texture from file

	spirte_background.setTexture(background);// sets the texture as sprite

	spirte_background.setOrigin(0.f, 0.f); //sets the origin of the texture
	spirte_background.setPosition(-4.15f, -3.f); //sets the position of the texture
	spirte_background.scale(0.004f, 0.0035f); //sets the scale of the texture
	
}

void Background::ballsIn()
{
	if (!font.loadFromFile("./assets/font/freshman.ttf"))
	{
		std::cout << "Error failed Loading Font" << std::endl;
		exit(0);
	}
	
	text.setFont(font);                
	text.setString("Balls In:");              
	text.setCharacterSize(30);          
	text.setScale(0.01f, 0.01);       
	text.setFillColor(sf::Color::Black); 
	text.setPosition(-3.5f, 1.8f);      
	
	text1.setFont(font);      
	text1.setString("Instructions: Pot Balls!");               
	text1.setCharacterSize(40);          
	text1.setScale(0.01f, 0.01);      
	text1.setFillColor(sf::Color::Black); 
	text1.setPosition(-2.5f, 2.3f);      

	
}

void Background::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	
	target.draw(spirte_background);
	target.draw(text);
	target.draw(text1);
	
}

