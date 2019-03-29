#pragma once

#include "staticSensor.h"
#include "balls.h"

#include "dynamicCircle.h"


class pocket_Sensor : public StaticSensor
{
private:

public:
	pocket_Sensor() {}; //!< Default constructor
	pocket_Sensor(b2World * world, sf::Vector2f position, sf::Vector2f size, float orientation, Balls*balls);
	void onAction(b2Body * other);
	void offAction(b2Body * other);
	Balls * o_balls;

};