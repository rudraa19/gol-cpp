#ifndef GOL_H
#define GOL_H

#include <vector>
using namespace std;

class Gol
{
private:
    int GRID_SIZE;
    vector<vector<int>> grid;
    int count_neighbour(int x, int y);

public:
    Gol(int gridSize);
    void setup();
    void display_grid();
    void update_grid();
};

#endif