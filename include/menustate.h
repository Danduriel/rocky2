#ifndef MENUSTATE_H
#define MENUSTATE_H

#include <gamestate.h>


class menustate : public gamestate
{
    public:
        void init(engine* game);
        void cleanup();

        void pause();
        void resume();

        void handleEvents(engine* game);
        void update(engine* game);
        void draw(engine* game);

        static menustate* instance()
        {
            return &m_menustate;
        }

    protected:
        menustate(){}
        //virtual ~teststate();

    private:
//        sf::CircleShape shape(100.f);
        static menustate m_menustate;

        sf::Sprite m_sprite_background;
        sf::Text m_text_title;
        sf::Text m_text_help;

        sf::Font m_bold_font;
        sf::Font m_funk;

        sf::Texture m_texture_background;
        //Button Texturen
        sf::Texture m_texture_play;
        sf::Texture m_texture_help;
        sf::Texture m_texture_credits;
        sf::Texture m_texture_quit;

};

#endif // MENUSTATE_H
