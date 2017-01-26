#include "teststate.h"

teststate teststate::m_teststate;

//teststate::teststate(){}

void teststate::init(engine* game)
{
    shape.setRadius(100.f);
    shape.setFillColor(sf::Color::Red);
}
void teststate::cleanup(){}

void teststate::pause(){}
void teststate::resume(){}

void teststate::handleEvents(engine* game)
{
    sf::Event event;

        while (game->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                game->window.close();

            if(event.type == sf::Event::KeyPressed)
			{
				if(event.key.code == sf::Keyboard::R)
				{
					shape.setFillColor(sf::Color::Green);
				}
			}
        }


}
void teststate::update(engine* game)
{

}
void teststate::draw(engine* game)
{
    game->window.clear();
    game->window.draw(shape);
    game->window.display();
}
