#pragma once

#include "staticSensor.h"
#include "balls.h"
#include <iostream>
#include "dynamicCircle.h"

class pocketSensor : public StaticSensor
{
private:

public:
	pocketSensor() {}; //!< Default constructor
	pocketSensor(b2World * world, sf::Vector2f position,sf::Vector2f size, float orientation, DynamicCircle*ball, Balls *balls);
	void onAction(b2Body * other);//!<when something collides will do a action
	void offAction(b2Body * other);//!<Dont really need but does something when collision is over 
	
	DynamicCircle * m_ball;//!<pointer to the ball with controls
	Balls * o_balls;//!<pointer to balls

};