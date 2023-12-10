#include <iostream>
#include <vector>
#include <assert.h>

class Solution
{
public:
    std::vector<std::vector<int>> transpose(std::vector<std::vector<int>> &matrix)
    {
        std::vector<std::vector<int>> transpose(matrix[0].size(), std::vector<int>(matrix.size()));
        for (size_t i = 0; i < matrix.size(); i++)
        {
            for (size_t j = 0; j < matrix[0].size(); j++)
            {
                transpose[j][i] = matrix[i][j];
            }
        }
        return transpose;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    std::vector<std::vector<int>> vec = {{1, 2, 3}, {4, 5, 6}};
    std::vector<std::vector<int>> result = {{1, 4},
                                            {2, 5},
                                            {3, 6}};
    assert(solution.transpose(vec) == result);

    return 0;
}