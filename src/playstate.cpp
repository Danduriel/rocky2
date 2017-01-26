#include "playstate.h"

playstate playstate::m_playstate;

void playstate::init(engine* game)
{
    if (!m_texture_background.loadFromFile("assets/bg_day.png")){}
    if (!m_texture_backgroundTwo.loadFromFile("assets/bg_night.png")){}
    if (!m_texture_mountains.loadFromFile("assets/bg_menu.png")){}
    if (!m_texture_coin.loadFromFile("assets/btn_play.png")){}
    if (!m_texture_meteor.loadFromFile("assets/btn_play.png")){}

    if (!m_bold_font.loadFromFile("assets/Roboto-Bold.ttf")){}

    // Set starting Position
    game->rocky.m_currentVelocity = game->rocky.boost;
    game->rocky.m_position.x = 640;
    game->rocky.m_position.y =0;
}

void playstate::cleanup(){}

void playstate::pause(){}
void playstate::resume(){}

void playstate::handleEvents(engine* game)
{
    sf::Event event;

        while (game->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                game->window.close();

            if(event.type == sf::Event::KeyPressed)
			{
				if(event.key.code == sf::Keyboard::Left)
				{
					m_player_direction = LEFT;
				}
				if(event.key.code == sf::Keyboard::Right)
				{
					m_player_direction = RIGHT;
				}
			}
        }


}
void playstate::update(engine* game)
{
    //Apllying delta to x coordinate of player
    sf::Vector2f delta;

    if(m_player_direction==LEFT)
    {
        delta = sf::Vector2f(-5,0);
    }
    else if(m_player_direction==RIGHT)
    {
        delta = sf::Vector2f(5,0);
    }
    else
    {
        delta = sf::Vector2f(0,0);
    }
    delta.y -= game->rocky.m_currentVelocity;
    game->rocky.m_currentVelocity -= m_gravity;


    //Setting new Player Location
    game->rocky.m_position.x += delta.x;
    //Can't be out of screen
    if(game->rocky.m_position.x <0) // Left screen side
    {
        game->rocky.m_position.x = 0;
    }
    else if(game->rocky.m_position.x + 80 > 720) // Right screen side
    {
        game->rocky.m_position.x = 720;
    }

    //Calculate Transparency value for background change
    m_transparency = 255 - game->rocky.m_position.y/(1500*100);

    // ADD COIN COLLECTION HERE

    // ADD MEET DADDY HERE

    // ADD ROCKY TO INFINTY AND BEYOND HERE !!!


}
void playstate::draw(engine* game)
{
    //Clear Up Last frame
    game->window.clear();

    //Draw Level

    //Day Background
    m_sprite_background.setTexture(m_texture_background); // Day
    game->window.draw(m_sprite_background);

    //Night Background fades in with Transparency
    m_sprite_backgroundTwo.setTexture(m_texture_backgroundTwo); //NightSky
    m_sprite_backgroundTwo.setColor(sf::Color(255, 255, 255, m_transparency));
    game->window.draw(m_sprite_backgroundTwo);

    //sf::Sprite m_sprite_mountains; //Starting screen

    //Draw Rocket

    //Draw Coins

    //Draw Meteors

    //Draw UI
       // sf::Text m_text_coins;        //Counter collected coins
        //sf::Text m_text_height;

    //Display frame
    game->window.display();
}
