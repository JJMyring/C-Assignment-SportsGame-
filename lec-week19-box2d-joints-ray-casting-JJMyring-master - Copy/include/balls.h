#pragma once


#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include "physicalThing.h"

class Balls : public sf::CircleShape, public PhysicalThing
{
private:
	bool recall = false;  //!< boolean for reseting the ball 
public:
	
	Balls() {};
	Balls(b2World * world, const sf::Vector2f& position, const float radius, const float orientation); //!< Complete contructor
	void update(); //!< Update rendering infomation 
	void draw(sf::RenderTarget &target, sf::RenderStates states) const; //!< Overridden drawing method to include line to allow users to see oreintation of the ball
    void pot();
	bool getReset(); //!< boolean for reset
	void setReset(); //!< reset
};