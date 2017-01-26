#include "gamestate.h"

/*gamestate::gamestate()
{
    //ctor
}
*/
gamestate::~gamestate()
{
    //dtor
}
void gamestate::init(){}
void gamestate::cleanup(){}

void gamestate::pause(){}
void gamestate::resume(){}

void gamestate::handeEvents(engine* game){}
void gamestate::update(engine* game){}
void gamestate::draw(engine* game){}

