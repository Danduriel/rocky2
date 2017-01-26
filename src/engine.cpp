#include "engine.h"
#include "gamestate.h"

engine::engine()
{
    //ctor
}

engine::~engine()
{
    //dtor
}

void engine::init(int width, int height, std::string title)
{
    //create sfml window and shit
    window.create(sf::VideoMode(width, height),title);
}

void engine::cleanup()
{
    while ( !states.empty() )
    {
        states.back()->cleanup();
        states.pop_back();
    }
    //helper::debugMsg("engine::cleanup")

}

void engine::changestate(gamestate* state)
{
    // cleanup the current state
    if ( !states.empty() )
    {
        states.back()->cleanup();
        states.pop_back();
    }

    // store and init the new state
    states.push_back(state);
    states.back()->init(this);
}

void engine::pushState(gamestate* state)
{
    // pause current state
    if ( !states.empty() )
    {
        states.back()->pause();
    }

    // store and init the new state
    states.push_back(state);
    states.back()->init(this);
}

void engine::popState()
{
    if ( !states.empty() )
    {
        states.back()->cleanup();
        states.pop_back();
    }

    if(!states.empty())
    {
        states.back()->resume();
    }
}

void engine::handleEvents()
{
    states.back()->handleEvents(this);
}

void engine::update()
{
    states.back()->update(this);
}

void engine::draw()
{
    states.back()->draw(this);
}
