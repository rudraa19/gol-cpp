#include <iostream>
#include "gol.h"
#include <unistd.h>

#define GRID_SIZE 100

using namespace std;

int main()
{
    Gol gol(GRID_SIZE);
    gol.setup();
    cout << "\033[2J\033[1;1H";

    while (true)
    {
        gol.display_grid();
        gol.update_grid();
        cout << "\033[2J\033[1;1H";
        usleep(0.01 * 100 * 10000);
    }
    return 0;
}