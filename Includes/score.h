#ifndef score_h
#define score_h
    class Score{
        private:
        int userScore = 0;
        int gamesPlayed = 0;
        int rounds = 10;
        public:
        // Mutator
        void setRounds();
        void incScore();
        void incGamesPlayed();
        void reset();
        void setGamesPlayed(int rounds);
        // Accessor
        int getScore() const;
        int getGamesPlayed() const;
        int getNumRounds() const;
        // Constructor
        Score();
        ~Score();
    };
#endif