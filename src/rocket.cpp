#include "rocket.h"

rocket::rocket()
{
    //ctor
}

rocket::rocket(std::vector<upgrade*> upgradeList)
{
	if (!m_texture_rocket.loadFromFile("assets/rocket_basic.png"))
	{
    	//TODO
	}

	rocketbody = NULL;
	rocketgoggles  = NULL;
	rocketwings  = NULL;
	rocketbooster  = NULL;
	rockettail  = NULL;

	coolness = 0;
	boost = 0;
	aerodynamic = 0;
}

void rocket::draw(sf::RenderTarget& target,sf::RenderStates states)const
{

}
