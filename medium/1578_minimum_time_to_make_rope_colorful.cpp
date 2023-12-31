#include <iostream>
#include <vector>
#include <cassert>

// Runtime: 304ms; Beats 5.96% of users with C++
// Memory:  95.60MB; Beats 99.55% of users with C++
class Solution
{
public:
    int minCost(std::string colors, std::vector<int> &neededTime)
    {
        int time = 0;
        int prev = neededTime[0];
        for (size_t i = 1; i < neededTime.size(); i++)
        {
            if (colors[i - 1] == colors[i])
            {
                time += std::min(prev, neededTime[i]);
                prev = std::max(prev, neededTime[i]);
            }
            else
            {
                prev = neededTime[i];
            }
        }

        return time;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    std::string colors = "abaac";
    std::vector<int> neededTime = {1, 2, 3, 4, 5};
    assert(solution.minCost(colors, neededTime) == 3);

    colors = "aabaa";
    neededTime = {1, 2, 3, 4, 1};
    assert(solution.minCost(colors, neededTime) == 2);

    colors = "brbbrbbb";
    neededTime = {1, 4, 2, 4, 3, 3, 2, 5};
    assert(solution.minCost(colors, neededTime) == 7);

    return 0;
}