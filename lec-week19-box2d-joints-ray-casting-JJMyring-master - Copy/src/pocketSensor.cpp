#include "pocketSensor.h"

pocketSensor::pocketSensor(b2World * world, sf::Vector2f position, sf::Vector2f size, float orientation, DynamicCircle*ball, Balls *balls)
{
	initRectangle(world, position, size, orientation);

	m_ball = ball;
	o_balls = balls;
	setFillColor(sf::Color::Black);
}

void pocketSensor::onAction(b2Body * other)
{
	if (m_ball->getBody() == other)
	{
		m_ball->resetBall();
	}

	std::pair<std::string, void*>* pair = static_cast<std::pair < std::string, void* > *> (other->GetUserData());
	if (pair->first == typeid(Balls).name())
	{
		Balls * balls = static_cast<Balls *>(pair->second); //gets data
		balls->setReset(); //reset ball 
	}

}

void pocketSensor::offAction(b2Body * other)
{
	
}
