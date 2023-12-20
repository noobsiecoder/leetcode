#include <iostream>
#include <vector>
#include <assert.h>

// Runtime: 66ms; Beats 74.81% of users with C++
// Memory:  59.28MB; Beats 89.13% of users with C++
class Solution
{
public:
    int maxArea(std::vector<int> &height)
    {
        size_t i = 0, j = height.size() - 1;
        int maxAreaFromHeight = 0, area = 0;
        while (i < j)
        {
            if (height[i] <= height[j])
            {
                area = height[i] * (j - i);
                i++;
            }
            else
            {
                area = height[j] * (j - i);
                j--;
            }

            if (area > maxAreaFromHeight)
                maxAreaFromHeight = area;
        }

        return maxAreaFromHeight;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;

    std::vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    assert(solution.maxArea(heights) == 49);
    return 0;
}