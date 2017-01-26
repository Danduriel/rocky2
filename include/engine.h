#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "helper.h"
#include "string.h"

#include "rocket.h"

class gamestate;

class engine
{
    public:
        engine();
        virtual ~engine();

        void init(int width, int height, std::string title);
        void cleanup();

        void changestate(gamestate* state);
        void pushState(gamestate* state);
        void popState();

        void handleEvents();
        void update();
        void draw();

        bool running(){return m_running;}
        void quit(){m_running = false;}

        sf::RenderWindow window;

        rocket rocky;

    protected:

    private:
        std::vector<gamestate*> states;

        bool m_running;

};

#endif // ENGINE_H
