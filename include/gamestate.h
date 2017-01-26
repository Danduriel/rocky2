#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "engine.h"

class gamestate
{
    public:


        virtual void init(engine* game)=0;
        virtual void cleanup()=0;

        virtual void pause()=0;
        virtual void resume()=0;

        virtual void handleEvents(engine* game)=0;
        virtual void update(engine* game)=0;
        virtual void draw(engine* game)=0;

        void changeGamestate(engine* game, gamestate* state)
        {
            game->changestate(state);
        }

    protected:
        gamestate(){}
        //virtual ~gamestate();
    private:
};

#endif // GAMESTATE_H
