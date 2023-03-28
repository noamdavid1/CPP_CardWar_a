#include "player.hpp"

namespace ariel
{
    Player::Player() {};

    Player::Player(string name) // initialization of the constructor.
    {
        this->pname = name;
    };
    //prints the amount of cards left.
    int Player::stacksize() 
    {
        return 0;
    }
    //prints the amount of cards this player has won.
    int Player::cardesTaken()
    {
        return 0;
    }
}