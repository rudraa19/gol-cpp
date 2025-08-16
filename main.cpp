#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

const int GRID_SIZE = 100;

vector<vector<int>> grid;

void setup();
void display_grid();
void update_grid();
int count_neighbour(int x, int y);

int main()
{
    setup();
    while (true)
    {
        display_grid();
        update_grid();
    }
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

void update_grid()
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

int count_neighbour(int x, int y)
{
    int count = 0;
    for (int i = -1; i < 3; i++)
    {
        for (int j = -1; j < 3; j++)
        {
            count += grid[(i + x + GRID_SIZE) % GRID_SIZE][(j + y + GRID_SIZE) % GRID_SIZE];
        }
    }
    return count - grid[x][y];
}