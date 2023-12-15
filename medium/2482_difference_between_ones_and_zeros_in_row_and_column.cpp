#include <iostream>
#include <vector>
#include <assert.h>

class Solution
{
public:
    std::vector<std::vector<int>> onesMinusZeros(std::vector<std::vector<int>> &grid)
    {
        int row_s = grid.size();
        int column_s = grid[0].size();

        std::vector<int> onesRow(column_s);
        std::vector<int> onesCol(row_s);
        std::vector<std::vector<int>> mat(row_s, std::vector<int>(column_s));
        for (int i = 0; i < row_s; i++)
        {
            for (int j = 0; j < column_s; j++)
            {
                if (grid[i][j])
                {
                    onesRow[j]++;
                    onesCol[i]++;
                }
            }
        }
        for (int i = 0; i < row_s; i++)
        {
            for (int j = 0; j < column_s; j++)
            {
                mat[i][j] = (onesRow[j] + onesCol[i]) * 2 - row_s - column_s;
            }
        }
        return mat;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;

    std::vector<std::vector<int>> grid = {{0, 1, 1}, {1, 0, 1}, {0, 0, 1}};
    std::vector<std::vector<int>> new_grid = solution.onesMinusZeros(grid);
    assert(new_grid == std::vector<std::vector<int>>({{0, 0, 4}, {0, 0, 4}, {-2, -2, 2}}));

    grid = {{1, 1, 1}, {1, 1, 1}};
    new_grid = solution.onesMinusZeros(grid);
    assert(new_grid == std::vector<std::vector<int>>({{5, 5, 5}, {5, 5, 5}}));

    return 0;
}