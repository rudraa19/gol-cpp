#include "gol.h"
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

Gol::Gol(int gridSize) : GRID_SIZE(gridSize) {}

void Gol::setup()
{
    srand(time(NULL));
    for (int i = 0; i < GRID_SIZE; i++)
    {
        vector<int> temp;
        for (int j = 0; j < GRID_SIZE; j++)
        {
            temp.push_back(rand() % 2);
        }
        grid.push_back(temp);
    }
}

void Gol::display_grid()
{
    for (int i = 0; i < GRID_SIZE; i += 2)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            int top = grid[i][j];
            int bottom = 0;

            if (i + 1 < GRID_SIZE)
            {
                bottom = grid[i + 1][j];
            }

            if (top == 1 && bottom == 1)
                cout << "█";
            else if (top == 1 && bottom == 0)
                cout << "▀";
            else if (top == 0 && bottom == 1)
                cout << "▄";
            else
                cout << " ";
        }
        cout << endl;
    }
}

int Gol::count_neighbour(int x, int y)
{
    int count = 0;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            count += grid[(i + x + GRID_SIZE) % GRID_SIZE][(j + y + GRID_SIZE) % GRID_SIZE];
        }
    }
    return count - grid[x][y];
}

void Gol::update_grid()
{
    vector<vector<int>> next_state = grid;
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            int n = count_neighbour(i, j);
            if (grid[i][j] == 0 && n == 3)
                next_state[i][j] = 1;
            if (grid[i][j] == 1 && (n > 3 || n < 2))
                next_state[i][j] = 0;
        }
    }
    grid = next_state;
}