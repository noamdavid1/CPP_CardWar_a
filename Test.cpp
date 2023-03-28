#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

using namespace ariel;

TEST_CASE("start of the game")
{
    // Create two players with their names.
    Player p1("yarden");
    Player p2("maor");
    // until the game starts, players have no cards.
    CHECK(p1.cardesTaken() == 0);
    CHECK(p1.stacksize() == 0);
    CHECK(p2.cardesTaken() == 0);
    CHECK(p2.stacksize() == 0);
    Game(p1, p2); // create a game with two players.
    // at the beggining of the game the player has no cards that he won.
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
    // at the beggining of the game each player get 26 cards.
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
}

TEST_CASE("middle of the game")
{
    Player p1("yarden");
    Player p2("maor");
    Game game(p1, p2);
    bool gameon; //create a boolean varable which symbolized if the game is on.
    //at first there is 26 cards to each player.
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    game.playTurn();
    game.playTurn();
    //after 2 turns there is less then 26 and more then 0 cards in the stack to each player.
    CHECK(p1.stacksize() <= 26);
    CHECK(p2.stacksize() <= 26);
    CHECK(p1.cardesTaken() >= 0);
    CHECK(p2.cardesTaken() >= 0);
    //someone has won at least one card.
    if (p1.cardesTaken() > 1 || p2.cardesTaken() > 1)
    {
        gameon = true; //the game is on.
    }
    CHECK(gameon == true);
    for (int i = 0; i < 10; i++)
    {
        game.playTurn(); //plays 10 turns.
    }
    bool mybool1;
    if (p1.stacksize() < 26 || p2.stacksize() < 26) //there is less then 26 cards in the stack.
    {
        mybool1 = true;
    }
    CHECK(mybool1 == true);
    bool mybool2;
    if (p1.cardesTaken() >= 0 || p2.cardesTaken() >= 0) //someone has won a card.
    {
        mybool2 = true;
    }
    CHECK(mybool2 == true);
}

TEST_CASE("end of the game")
{
    Player p1("yarden");
    Player p2("maor");
    Game game(p1, p2);
    game.playAll(); // plays all the turns.
    CHECK(p1.cardesTaken() + p1.stacksize() + p2.cardesTaken() + p2.stacksize() == 52); //there is 52 cards in total.
    //cant play. no turns left.
    CHECK_THROWS(game.playAll()); 
    CHECK_THROWS(game.playTurn());
}