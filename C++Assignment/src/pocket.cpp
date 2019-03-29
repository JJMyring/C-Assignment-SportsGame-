#pragma once
#include "pocket.h"
#include <iostream>


pocket_Sensor::pocket_Sensor(b2World * world, sf::Vector2f position, sf::Vector2f size, float orientation, Balls*balls)
{
	initRectangle(world, position, size, orientation);

	o_balls = balls;

	setFillColor(sf::Color::Blue);
}

void pocket_Sensor::onAction(b2Body * other)
{
	
}

void pocket_Sensor::offAction(b2Body * other)
{

}
