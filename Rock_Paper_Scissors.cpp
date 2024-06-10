#include <iostream>
#include <random>
#include "Includes/game.h"

using namespace std;

int main(){
    // Start game
    Game* thisGame = new Game;
    thisGame->play();
    delete thisGame;
};