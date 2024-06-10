#include "game.h"
#include "score.h"
#include <random>
#include <iostream>

using namespace std;

void Game::setUserInp(){
    int userIn;
    cout << "Enter 1 for Rock.\nEnter 2 for Paper.\nEnter 3 for Scissors.\nEnter 0 or any letter to exit.\n" << "Rock, Paper, or Scissors? ";
    cin >> userIn;
    this-> userInp = userIn;
}
void Game::play(){
    // Init mersenne twister rng
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist3(1,3);
    this->gameInfo->reset();
    this->gameInfo->setRounds();
    while (this->gameInfo->getGamesPlayed() < this->gameInfo->getNumRounds()){
        this->setUserInp();
        this->botInp = dist3(rng);
        this->check(this->userInp, this->botInp);
        this->gameInfo->incGamesPlayed();
    }
    cout << "That was fun! You are a good competitor!" << endl;
    this->score();
    this->playAgain();
}
void Game::check(int userIn, int botIn) const{
    switch (userIn){
        // Exit command
        case 0:
            this->score();
            cout << "Goodbye." << endl;
            this->gameInfo->setGamesPlayed(this->gameInfo->getNumRounds());
            break;
        // Rock
        case 1:
            cout << "You: Rock" << endl;
            switch (botIn){
                //rock
                case 1:
                    cout << "Them: Rock" << endl;
                    cout << "Tie! So close!" << endl;
                    break;
                // Paper        
                case 2:
                    cout << "Them: Paper" << endl;
                    cout << "Lose! Better luck next time!" << endl;
                    break;
                // Scissor
                case 3:
                    cout << "Them: Scissor" << endl;
                    cout << "Victory! Nice one!" << endl;
                    this->gameInfo->incScore();
                    break;
            }
            break;
        // Paper        
        case 2:
            cout << "You: Paper" << endl;
            switch (botIn){
                //rock
                case 1:
                    cout << "Them: Rock" << endl;
                    cout << "Victory! Nice one!" << endl;
                    this->gameInfo->incScore();
                    break;
                // Paper        
                case 2:
                    cout << "Them: Paper" << endl;
                    cout << "Tie! So close!" << endl;
                    break;
                // Scissor
                case 3:
                    cout << "Them: Scissor" << endl;
                    cout << "Lose! Better luck next time!" << endl;
                    break;
            }
            break;
        // Scissor
        case 3:
            cout << "You: Scissor" << endl;
            switch (botIn){
                //rock
                case 1:
                    cout << "Them: Rock" << endl;
                    cout << "Lose! Better luck next time!" << endl;
                    break;
                // Paper        
                case 2:
                    cout << "Them: Paper" << endl;
                    cout << "Victory! Nice one!" << endl;
                    this->gameInfo->incScore();
                    break;
                // Scissor
                case 3:
                    cout << "Them: Scissor" << endl;
                    cout << "Tie! So close!" << endl;
                    break;
            }
            break;
        // Non-valid input
        default:
            cout << "Error! Please input a valid selection" << endl;
            this->gameInfo->setGamesPlayed(this->gameInfo->getGamesPlayed() - 1);
            break;
    }
}
void Game::score() const{
    cout << "Score: " << this->gameInfo->getScore() << "/" << this->gameInfo->getGamesPlayed() << endl;
}
void Game::playAgain(){
    char again;
    cout << "Do you want to play again? (y/n) ";
    cin >> again;
    switch (again)
    {
    case 'y':
        this->play();
        break;
    case 'n':
        cout << "Goodbye!" << endl;
        break;
    default:
        cout << "I didn't understand that, please try again." << endl;
        this->playAgain();
        break;
    }
}
Game::Game(){
    this->gameInfo = new Score;
}
Game::~Game(){
    delete this->gameInfo;
}