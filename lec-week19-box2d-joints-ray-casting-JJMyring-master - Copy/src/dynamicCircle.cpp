/*!
\file dynamicCircle.cpp
*/

#include "dynamicCircle.h"


DynamicCircle::DynamicCircle(b2World * world, const sf::Vector2f& position, const float radius, const float orientation)
{
	b2BodyDef l_bodyDef;
	b2CircleShape l_shape;
	b2FixtureDef l_fixtureDef;


	l_bodyDef.type = b2_dynamicBody;
	l_bodyDef.position.Set(position.x, position.y);
	l_bodyDef.angle = orientation * DEG2RAD;

	m_body = world->CreateBody(&l_bodyDef);
	m_body->SetUserData(this); // used by our contact listener

	l_shape.m_radius = radius;

	l_fixtureDef.density = mk_fDensity;
	l_fixtureDef.friction = mk_fFriction;
	l_fixtureDef.restitution = mk_fRestitution;
	l_fixtureDef.shape = &l_shape;

	m_body->CreateFixture(&l_fixtureDef);
	m_body->SetLinearDamping(0.2f);
	m_body->SetAngularDamping(0.2f);

	setPosition(position);
	setRadius(radius);
	setOrigin(radius, radius);
	setRotation(orientation);
	setFillColor(sf::Color::White);
}

void DynamicCircle::update()
{
	// Check whether the circle has stopped (simualated ground friction)
	m_stopped = m_body->GetLinearVelocity().Length() < 0.1f;
	//If stopped trim any remaining velocity
	if (m_stopped)
	{
		m_body->SetLinearVelocity(b2Vec2(0.f, 0.f));
		m_body->SetAngularVelocity(0.0f);
	}
	if (m_resetBall)
	{
		reset(); //reset function is called
		m_resetBall = false; //turn m_resetball from true to false
		return; //return data
	}

	b2Vec2 pos = m_body->GetPosition();
	setPosition(pos.x, pos.y);
	float angle = m_body->GetAngle()* RAD2DEG;
	setRotation(angle);
}

void DynamicCircle::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw((sf::CircleShape)*this); // Draw the Circle Shape
}

void DynamicCircle::applyImpulse(b2Vec2 impulse)
{
	m_body->ApplyLinearImpulseToCenter(impulse, true);
}

void DynamicCircle::accel(b2Vec2 accel)
{
	
}

bool DynamicCircle::isStopped() const
{
	return m_stopped;
}

void DynamicCircle::reset()
{
	m_body->SetTransform(b2Vec2(-1.35f, 0.f), 0.f); //set transfrom of cueball back to position
	m_body->SetLinearVelocity(b2Vec2(0.f, 0.f)); //set the velocity back to 0
	m_body->SetAngularVelocity(0.0f);
}


