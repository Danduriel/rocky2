#include "engine.h"
#include "helper.h"

// Add only very first state game should jump into
#include "teststate.h"
#include "menustate.h"
#include "playstate.h"


int main()
{
    //Instance of game engine (Holds the sfml screen)
    engine game;

    //Mainly to initialise the sf::window
    game.init(1280,800,"Rocky the Rocket's Path to infinity and beyond");

    //Set start State
    game.changestate(menustate::instance());


    //Main Loop - No touching nessecary
    //Add framelimit
    while (game.running())
    {
        //printf("mainloop\n");
        game.handleEvents();
        game.update();
        game.draw();
    }

    game.cleanup();

    return 0;
}
