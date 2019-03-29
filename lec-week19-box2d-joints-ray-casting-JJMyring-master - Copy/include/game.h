#pragma once

/*!
\file game.h
*/

//All classes that are required 
#include "background.h"
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "staticBlock.h"
#include "dynamicBlock.h"
#include "dynamicCircle.h"
#include "pocketSensor.h"
#include "rotatingDoor.h"
#include "Balls.h"
#include "SensorContactListener.h"
#include "ray.h"
#include "pocket.h"

#include "SFMLDebugDraw.h"
using namespace std;
#define _USE_MATH_DEFINES
#include <math.h>

/*! \class Game
\brief Holds all information about the game which allows it to render/update.
*/

class Game : public sf::Drawable {
private:
	sf::View m_view; //!< The view maps from physical co-ordinates to rendering co-ordinates
	sf::Vector2f m_worldSize = sf::Vector2f(8.f, 6.f); //!< Size of the physical worlds is 8 X 6 metres
	Background background;
	b2World* m_pWorld = nullptr; //!< Pointer to the Box2D world.  Using pointers as BOX2D has it's own memory management
	const int mk_iVelIterations = 7; //!< On each update there will be 7 velocity iterations in the physics engine
	const int mk_iPosIterations = 5; //!< On each update there will be 5 position iterations on each update
	const b2Vec2 mk_gravity = b2Vec2(0.f, 0.f); //!< Gravity of the game however in my case I dont need it on
	float m_ballDirection; //!< Angle heading to fire the ball in radians
	bool m_debug = false; //!< Toggle for debug drawing
	void toggleDebug() { m_debug = !m_debug; } //!< Toggle for debug drawing

	Balls o_balls[10]; //!< A collection of moving balls. 
	Ray m_ray; //!< A ray which allows uss to the direction the ball is heading
	DynamicCircle m_ball; //!< Main ball which will be moving with controls
	
    SensorContactListener m_listener; //!< Contact listener for collisions
    SFMLDebugDraw m_debugDraw; //!< Box2D debug drawing

	std::vector<StaticBlock> m_staticBlocks; //!< boxes that will static in the game
	std::vector<pocketSensor> m_pressure; //!< sensor that will the holes in the game

		
public:
	Game(); //!< Constructor which sets up the game
	~Game(); //!< Destructor which cleans all the pointer memory up
	void update(float timestep); //!< Update the game with give timestep
	void draw(sf::RenderTarget &target, sf::RenderStates states) const; //!< Draw the game to the render context
	void processKeyPress(sf::Keyboard::Key code); //!< Controls for the ray line
	
};
