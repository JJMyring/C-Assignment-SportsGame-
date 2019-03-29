/*!
\file game.cpp
*/
#include "game.h"

Game::Game()
{
	m_view.setCenter(0.f, 0.f);//sets the view point in the middle
	m_view.setSize(m_worldSize);
	background.ballsIn();//
	background.setTable();//table from background class
	m_pWorld = new b2World(mk_gravity);
	m_debugDraw.setWorld(m_pWorld);
	
	// sets all the static boxes in line with the table 

	m_staticBlocks.push_back(StaticBlock(m_pWorld, sf::Vector2f(-1.55f, -1.63f), sf::Vector2f(2.785f, 0.1f), 0.f));//Top left side of table
	m_staticBlocks.push_back(StaticBlock(m_pWorld, sf::Vector2f(1.6f, -1.63f), sf::Vector2f(2.785f, 0.1f), 0.f));//Top right side of table
	m_staticBlocks.push_back(StaticBlock(m_pWorld, sf::Vector2f(-1.55f, 1.46f), sf::Vector2f(2.785f, 0.1f), 0.f));//bottom left side of table
	m_staticBlocks.push_back(StaticBlock(m_pWorld, sf::Vector2f(1.57f, 1.46f), sf::Vector2f(2.785f, 0.1f), 0.f));//bottom right side of table
	m_staticBlocks.push_back(StaticBlock(m_pWorld, sf::Vector2f(-3.22f, -0.1f), sf::Vector2f(2.6f, 0.1f), 90.f));//Left side of table
	m_staticBlocks.push_back(StaticBlock(m_pWorld, sf::Vector2f(3.22f, -0.1f), sf::Vector2f(2.6f, 0.1f), 90.f));//Right side of table
	

	//o_balls.push_back(Balls(m_pWorld, sf::Vector2f(1.1f, 0.f), 0.12f, 0.f));//front ball
	//o_balls.push_back(Balls(m_pWorld, sf::Vector2f(1.32f, 0.124f), 0.12f, 0.f));//2nd row bottom
	//o_balls.push_back(Balls(m_pWorld, sf::Vector2f(1.32f, -0.124f), 0.12f, 0.f));//2nd row top
	//o_balls.push_back(Balls(m_pWorld, sf::Vector2f(1.54f, 0.f), 0.12f, 0.f));//3rd row middle
	//o_balls.push_back(Balls(m_pWorld, sf::Vector2f(1.54f, -0.25f), 0.12f, 0.f));//3rd row top
	//o_balls.push_back(Balls(m_pWorld, sf::Vector2f(1.54f, 0.25f), 0.12f, 0.f));//3rd row top
    //o_balls.push_back(Balls(m_pWorld, sf::Vector2f(1.76f, 0.1f), 0.12f, 0.f));//4th row middle
	//o_balls.push_back(Balls(m_pWorld, sf::Vector2f(1.76f, -0.15f), 0.12f, 0.f));//4th row top
	//o_balls.push_back(Balls(m_pWorld, sf::Vector2f(1.76f, 0.35f), 0.12f, 0.f));//4th 2nd bottom
	//o_balls.push_back(Balls(m_pWorld, sf::Vector2f(1.76f, -0.4f), 0.12f, 0.f));//4th bottom
	m_ballDirection = 0.0f;

	//array of balls besides the cue ball
	o_balls[0] = Balls(m_pWorld, sf::Vector2f(1.1f, 0.f), 0.12f, 0.0f);
	o_balls[1] = Balls(m_pWorld, sf::Vector2f(1.32f, 0.124f), 0.12f, 0.0f);
	o_balls[2] = Balls(m_pWorld, sf::Vector2f(1.32f, -0.124f), 0.12f, 0.0f);
	o_balls[3] = Balls(m_pWorld, sf::Vector2f(1.54f, 0.f), 0.12f, 0.0f);
	o_balls[4] = Balls(m_pWorld, sf::Vector2f(1.54f, -0.25f), 0.12f, 0.0f);
	o_balls[5] = Balls(m_pWorld, sf::Vector2f(1.54f, 0.25f), 0.12f, 0.0f);
	o_balls[6] = Balls(m_pWorld, sf::Vector2f(1.76f, 0.1f), 0.12f, 0.0f);
	o_balls[7] = Balls(m_pWorld, sf::Vector2f(1.76f, -0.15f), 0.12f, 0.0f);
	o_balls[8] = Balls(m_pWorld, sf::Vector2f(1.76f, 0.35f), 0.12f, 0.0f);
	o_balls[9] = Balls(m_pWorld, sf::Vector2f(1.76f, -0.4f), 0.12f, 0.0f);
	
	//this code sets the sensor on the hole area on the static image
	for (auto& balls : o_balls) 
	{ 
	m_pressure.resize(6);
	m_pressure[0] = pocketSensor(m_pWorld, sf::Vector2f(0.f, 1.72f), sf::Vector2f(.8f * .8f, 0.6f * 0.5f), 0.f, &m_ball, &balls);
	m_pressure[0].setUserData(&m_pressure[0]);
	m_pressure[1] = pocketSensor(m_pWorld, sf::Vector2f(0.f, -1.87f), sf::Vector2f(.8f * .8f, 0.6f * 0.5f), 0.f, &m_ball, &balls);
	m_pressure[1].setUserData(&m_pressure[1]);
	m_pressure[2] = pocketSensor(m_pWorld, sf::Vector2f(3.2f, -1.77f), sf::Vector2f(.8f * .8f, 0.6f * 0.5f), 45.f, &m_ball, &balls);
	m_pressure[2].setUserData(&m_pressure[2]);
	m_pressure[3] = pocketSensor(m_pWorld, sf::Vector2f(3.2f, 1.64f), sf::Vector2f(.8f * .8f, 0.6f * 0.5f), -45.f, &m_ball, &balls);
	m_pressure[3].setUserData(&m_pressure[3]);
	m_pressure[4] = pocketSensor(m_pWorld, sf::Vector2f(-3.2f, 1.64f), sf::Vector2f(.8f * .8f, 0.6f * 0.5f), 45.f, &m_ball, &balls);
	m_pressure[4].setUserData(&m_pressure[4]);
	m_pressure[5] = pocketSensor(m_pWorld, sf::Vector2f(-3.2f, -1.64f), sf::Vector2f(.8f * .8f, 0.6f * 0.5f), -45.f, &m_ball, &balls);
	m_pressure[5].setUserData(&m_pressure[5]);
	
}
	for (Balls& balls : o_balls)balls.setUserData(new pair <string, void*>(typeid(decltype(balls)).name(), &balls));
	//main ball with the ray below it
	m_ball = DynamicCircle(m_pWorld, sf::Vector2f(-1.5f, 0.f), 0.12f, m_ballDirection);//Adding in the main ball with the laser
	m_ray = Ray(m_pWorld, 20.f, sf::Color::Magenta);
	
	m_pWorld->SetContactListener(&m_listener);//contact listener
}

Game::~Game()
{
	// Clean up all pointers
	delete m_pWorld;
	m_pWorld = nullptr;
}

void Game::update(float timestep)
{
	// Update the world
	m_pWorld->Step(timestep, mk_iVelIterations, mk_iVelIterations);

	// update cueball
	m_ball.update();
	//updates the other balls
	for (auto& balls : o_balls) balls.update();

	//for (Balls& ball : o_balls) ball.update();


	if (m_ball.isStopped()) {
		m_ray.setDirection(m_ballDirection);
		m_ray.cast(m_ball.getPosition());
	}

	for (int i = 0; i < 10; i++)//loop for the other balls to be able to reset
	{
		if (o_balls[i].getReset())
		{
			o_balls[i].pot();
		}

	}
		
		// Delete debug shapes
		if (m_debug) m_debugDraw.clear();
	}


void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	// Set the view
	target.setView(m_view);
    target.draw(background);

	// Draw everything
	if(m_ball.isStopped()) target.draw(m_ray);
	for (auto balls : o_balls) target.draw(balls);
	//for (StaticBlock block : m_staticBlocks) target.draw(block); //Code to draw the blocks remove the // to draw the boxes
	

	/*!\

	for (auto &cone : m_pressure) {
		target.draw(cone);
	}
     */

	target.draw(m_ball);
    
	// Debug Draw
	if(m_debug) target.draw(m_debugDraw);
}

void Game::processKeyPress(sf::Keyboard::Key code)
{
	switch (code)
	{
	case sf::Keyboard::Tab:
		toggleDebug();
		break;
	case sf::Keyboard::Space:
		if(m_ball.isStopped()) m_ball.applyImpulse(b2Vec2(0.05f * cosf(m_ballDirection), 0.05f * sinf(m_ballDirection)));
		break;
	case sf::Keyboard::Right:
		m_ballDirection += 0.05f;
		if (m_ballDirection > 2.0f * M_PI) m_ballDirection -= 2.0f * M_PI;
		break;
	case sf::Keyboard::Left:
		m_ballDirection -= 0.05f;
		if (m_ballDirection < 0.0f) m_ballDirection += 2.0f * M_PI;
		break;
	}
}

