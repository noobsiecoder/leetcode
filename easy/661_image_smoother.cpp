#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>

// Runtime: 41ms; Beats 69.85% of users with C++
// Memory:  22.08MB; Beats 59.38% of users with C++
class Solution
{
public:
    std::vector<std::vector<int>> imageSmoother(std::vector<std::vector<int>> &img)
    {
        size_t row = img.size();
        size_t column = img[0].size();
        std::vector<std::vector<int>> img_smoothened_matrix(row, std::vector<int>(column));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                int count = 0;
                for (int x = i - 1; x <= i + 1; ++x)
                {
                    for (int y = j - 1; y <= j + 1; ++y)
                    {
                        if (x < 0 || x >= row || y < 0 || y >= column)
                            continue;
                        img_smoothened_matrix[i][j] += img[x][y];
                        ++count;
                    }
                }
                img_smoothened_matrix[i][j] /= count;
            }
        }

        return img_smoothened_matrix;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    std::vector<std::vector<int>> img_matrix = {{100, 200, 100}, {200, 50, 200}, {100, 200, 100}};
    std::vector<std::vector<int>> img_smoothened_matrix = {{137, 141, 137}, {141, 138, 141}, {137, 141, 137}};
    assert(solution.imageSmoother(img_matrix) == img_smoothened_matrix);

    return 0;
}