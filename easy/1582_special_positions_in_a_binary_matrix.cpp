#include <iostream>
#include <vector>
#include <assert.h>

class Solution
{
public:
    int numSpecial(std::vector<std::vector<int>> &mat)
    {
        size_t row_s = mat.size();
        size_t column_s = mat[0].size();
        int value = 0;
        std::vector<int> rows(row_s);
        std::vector<int> columns(column_s);
        for (size_t i = 0; i < row_s; i++)
        {
            for (size_t j = 0; j < column_s; j++)
            {
                if (mat[i][j] == 1)
                {
                    ++rows[i];
                    ++columns[j];
                }
            }
        }

        for (size_t i = 0; i < row_s; i++)
        {
            for (size_t j = 0; j < column_s; j++)
            {
                if (rows[i] == 1 && columns[j] == 1 && mat[i][j] == 1)
                    ++value;
            }
        }

        return value;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;

    std::vector<std::vector<int>> mat = {{1, 0, 0}, {0, 0, 1}, {1, 0, 0}};
    assert(solution.numSpecial(mat) == 1);
    mat = {{1, 0, 0}, {0, 0, 0}, {0, 0, 1}};
    assert(solution.numSpecial(mat) == 2);
    mat = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    assert(solution.numSpecial(mat) == 3);

    return 0;
}