#pragma once

#include "staticSensor.h"
#include "slidingDoor.h"
using namespace std;

class Background : public sf::Drawable
{
private:
	
	sf::Texture background;//!<texture for background
	sf::Sprite spirte_background;  //!<spirte for the background
	sf::Font font; //!<font style  
	sf::Text text;//!<text for balls in
	sf::Text text1;//!<text for instructions

	
public:
	Background() {}; //!< Default constructor
	void setTable();//!<sets the static background which is the table 
	void ballsIn();//font  
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;  //!< constructor
};