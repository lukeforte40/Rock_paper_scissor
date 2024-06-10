#include "score.h"
#include <iostream>

using namespace std;

void Score::setRounds(){
    int numRounds;
    cout << "How many rounds would you like to play? ";
    cin >> numRounds;
    this->rounds = numRounds;
    if (this->getNumRounds() <= 0)
    {
        cin.clear();
        cin.ignore();
        cout << "Error! Rounds must be greater than 0." << endl;
        cout << "How many rounds would you like to play? ";
        cin >> numRounds;
        this->rounds = numRounds;
    }
}
void Score::incScore(){
    this->userScore++;
}
void Score::incGamesPlayed(){
    this->gamesPlayed++; 
}
void Score::reset(){
    this->userScore = 0;
    this->gamesPlayed = 0;
}
void Score::setGamesPlayed(int rounds){
    this->gamesPlayed = rounds;
}
int Score::getScore() const{
    return this->userScore;
}
int Score::getGamesPlayed() const{
    return this->gamesPlayed;
}
int Score::getNumRounds() const{
    return this->rounds;
}
Score::Score(){
    // null
}
Score::~Score(){
    // null
}