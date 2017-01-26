#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include <vector>

class gamestate;

class engine
{
    public:
        engine();
        virtual ~engine();

        void init();
        void cleanup();

        void changeState(gamestate* state);
        void pushState(gamestate* state);
        void popState();

        void handleevents();
        void update();
        void draw();

        bool running() {return m_running;}
        void quit(){m_running = false;}

        //Adjust here for different games!
      //  sf::RenderWindow window(sf::VideoMode(1280, 800), "Rocky the rocket's path to infinity and beyond!");

    protected:

    private:

        std::vector<gamestate*> states;

        bool m_running;
        bool m_fullscreen; // for later use
};

#endif // ENGINE_H
