#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

const int GRID_SIZE = 100;

vector<vector<int>> grid;

void setup();
void display_grid();

int main()
{
    setup();
    display_grid();
    return 0;
}

void setup()
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

void display_grid()
{
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}