#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

// Runtime: 259ms; Beats 20.97% of users with C++
// Memory:  66.61MB; Beats 70.65% of users with C++
class Solution
{
public:
    int maxWidthOfVerticalArea(std::vector<std::vector<int>> &points)
    {
        int maxWidth = 0;
        std::sort(points.begin(), points.end());
        for (size_t i = 1; i < points.size(); i++)
        {
            maxWidth = std::max(maxWidth, points[i][0] - points[i - 1][0]);
        }

        return maxWidth;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;

    std::vector<std::vector<int>> points = {{3, 1}, {9, 0}, {1, 0}, {1, 4}, {5, 3}, {8, 8}};
    assert(solution.maxWidthOfVerticalArea(points) == 3);

    points = {{8, 7}, {9, 9}, {7, 4}, {9, 7}};
    assert(solution.maxWidthOfVerticalArea(points) == 1);

    return 0;
}