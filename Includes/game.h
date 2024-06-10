#ifndef game_h
#define game_h
#include "score.h"
#include <random>
using namespace std;

class Game{
    private:
        int userInp;
        int botInp;
        Score* gameInfo;
    public:
        // Mutator
        void setUserInp();
        // Accessors
        void play();
        void check(int userIn, int botIn) const;
        void score() const;
        void playAgain();
        // Other
        Game();
        ~Game();
};
#endif