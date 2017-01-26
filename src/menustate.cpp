#include "menustate.h"

menustate menustate::m_menustate;

void menustate::init(engine* game)
{
    if (!m_texture_background.loadFromFile("assets/bg_menu.png"))
    {
        //to do
        //debug
        printf("did not load assets/bg_menu.png");

    }
    if (!m_texture_play.loadFromFile("assets/btn_play.png")){}
    if (!m_texture_help.loadFromFile("assets/btn_help.png")){}
    if (!m_texture_credits.loadFromFile("assets/btn_credits.png")){}
    if (!m_texture_quit.loadFromFile("assets/btn_quit.png")){}
    if (!m_bold_font.loadFromFile("assets/Roboto-Bold.ttf")){}
	if (!m_funk.loadFromFile("assets/Funk.ttf")){}
}

void menustate::cleanup(){}

void menustate::pause(){}
void menustate::resume(){}

void menustate::handleEvents(engine* game)
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
					//shape.setFillColor(sf::Color::Green);
				}
			}
        }


}
void menustate::update(engine* game)
{

}
void menustate::draw(engine* game)
{
    //delete old frame
    game->window.clear();

    //Stuff to be drawn in frame
	m_sprite_background.setTexture(m_texture_background);
	m_sprite_background.setPosition(0,0);
	game->window.draw(m_sprite_background);

	m_text_title.setFont(m_funk);
	m_text_title.setFillColor(sf::Color::Magenta);
	m_text_title.setString("Rocky the Rocket's Path To Infinity \nAND BEYOND ");
    m_text_title.setCharacterSize(40);
    m_text_title.setPosition(sf::Vector2f(game->window.getSize().x/2 - m_text_title.getLocalBounds().width/2,50));
    game->window.draw(m_text_title);


    m_text_help.setFont(m_bold_font);
    m_text_help.setFillColor(sf::Color::White);
    m_text_help.setString("Rocky the Rocket wants to meet his daddy.\nBut he is high up in the sky. :-( Help him get there!");
    m_text_help.setCharacterSize(30);
    m_text_help.setPosition(sf::Vector2f(game->window.getSize().x/2 - m_text_help.getLocalBounds().width/2,500));
    game->window.draw(m_text_help);


    //Show the rendered frame
    game->window.display();
}
