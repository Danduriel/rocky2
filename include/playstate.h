#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include <gamestate.h>

#define NONE 0
#define LEFT 1
#define RIGHT 2


class playstate : public gamestate
{
    public:
        void init(engine* game);
        void cleanup();

        void pause();
        void resume();

        void handleEvents(engine* game);
        void update(engine* game);
        void draw(engine* game);

        static playstate* instance()
        {
            return &m_playstate;
        }

    protected:
        playstate(){}
        //virtual ~playstate();

    private:
        static playstate m_playstate;

        float m_gravity;
        int m_player_direction;

        int m_coinsCollected;

        float m_transparency = 0.0;

        sf::Sprite m_sprite_background; // Day
        sf::Sprite m_sprite_backgroundTwo; //NightSky
        sf::Sprite m_sprite_mountains; //Starting screen

        sf::Text m_text_coins;        //Counter collected coins
        sf::Text m_text_height;         //Status Height


        sf::Font m_bold_font;

        sf::Texture m_texture_background;
        sf::Texture m_texture_backgroundTwo;
        sf::Texture m_texture_mountains;

        sf::Texture m_texture_coin;
        sf::Texture m_texture_meteor;



};

#endif // PLAYSTATE_H
