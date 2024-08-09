#include <vector>
#include <string>
#include <cassert>

// type alias for 2-dimensional vector class
template <class T>
using Vec2 = std::vector<std::vector<T>>;

// Runtime: 0ms; Beats 100.00% of users with C++
// Memory:  11.33MB; Beats 43.70% of users with C++
class Solution
{
private:
    bool isMagic(Vec2<int> &grid, std::size_t i, std::size_t j)
    {
        int idx[] = {0, 1, 2, 5, 8, 7, 6, 3};
        // build a string around the 3x3 grid's corners
        std::string str = "";
        // Cyclic string ranging from 1-9
        std::string check_str1 = "4381672943816729";
        std::string check_str2 = "9276183492761834";

        for (const std::size_t num : idx)
            str += std::to_string(grid[i + num / 3][j + num % 3]);

        return check_str1.find(str) != std::string::npos || check_str2.find(str) != std::string::npos;
    }

public:
    int numMagicSquaresInside(Vec2<int> &grid)
    {
        int nums = 0;

        for (std::size_t i = 0; i + 2 < grid.size(); i++)
            for (std::size_t j = 0; j + 2 < grid.size(); j++)
                // first number must be even and the number at the middle pivot must be 5
                if (grid[i][j] % 2 == 0 && grid[i + 1][j + 1] == 5)
                {
                    if (isMagic(grid, i, j))
                        nums += 1;
                    else
                        continue;
                }

        return nums;
    }
};

int main(int argv, char **argc)
{
    Solution solution = Solution();
    Vec2<int> arr = {{4, 3, 8, 4}, {9, 5, 1, 9}, {2, 7, 6, 2}};
    int res = solution.numMagicSquaresInside(arr);
    assert(res == 1);
}
