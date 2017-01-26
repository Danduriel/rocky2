#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>
#include "engine.h"

class gamestate : public sf::Drawable
{
    public:
        //gamestate();
        virtual ~gamestate();

        virtual void init();
        virtual void cleanup();

        virtual void pause();
        virtual void resume();

        virtual void handeEvents(engine* game) = 0;
        virtual void update(engine* game) = 0;
        virtual void draw(engine* game) = 0;

        void changeState(engine* game, gamestate* state)
        {
            game->changeState(state);
        }

    protected:
        gamestate(){}

    private:
};

#endif // GAMESTATE_H
