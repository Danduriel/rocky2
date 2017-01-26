#ifndef TESTSTATE_H
#define TESTSTATE_H

#include <gamestate.h>


class teststate : public gamestate
{
    public:
        void init(engine* game);
        void cleanup();

        void pause();
        void resume();

        void handleEvents(engine* game);
        void update(engine* game);
        void draw(engine* game);

        static teststate* instance()
        {
            return &m_teststate;
        }

    protected:
        teststate(){}
        //virtual ~teststate();

    private:
//        sf::CircleShape shape(100.f);
        static teststate m_teststate;

            sf::CircleShape shape;

};

#endif // TESTSTATE_H
