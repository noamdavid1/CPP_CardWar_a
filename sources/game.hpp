#pragma once

#include "player.hpp"

namespace ariel
{
    class Game
    {
    private:
        Player player_a;
        Player player_b;

    public:
        Game(Player playera, Player playerb); //constructor.

        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
    };
}
