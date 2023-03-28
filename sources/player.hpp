#pragma once

#include <string>


namespace ariel
{
    using namespace std;
    class Player
    {
    private:
        string pname;

    public:
        Player(); //defult constructor.
        Player(string name); //constructor.
        int stacksize();
        int cardesTaken();
    };

}