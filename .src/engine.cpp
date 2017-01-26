#include "engine.h"
#include <stdio.h>
engine::engine()
{
    //ctor
}

engine::~engine()
{
    //dtor
}

void engine::init(){}
void engine::cleanup()
{
    while(!states.empty() )
    {
        states.back()->cleanup();
        states.pop_back();
    }
    std::printf("debug: engine::cleanup");
}

void engine::changeState(gamestate* state)
{

}
void engine::pushState(gamestate* state){}
void engine::popState(){}

void engine::handleevents(){}
void engine::update(){}
void engine::draw(){}
