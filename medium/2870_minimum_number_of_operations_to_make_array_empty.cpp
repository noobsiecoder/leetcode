#include <cassert>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

// Runtime: 120ms; Beats 61.88% of users with C++
// Memory:  85.28MB; Beats 46.04% of users with C++
class Solution
{
public:
    int minOperations(std::vector<int> &nums)
    {
        std::unordered_map<int, u_int> numberFrequency;
        for (int num : nums)
        {
            ++numberFrequency[num];
        }

        int minOperations = 0;
        for (auto field : numberFrequency)
        {
            if (field.second == 1)
                return -1;
            else
                minOperations += std::ceil((double)field.second / 3);
        }

        return minOperations;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    std::vector<int> nums = {4, 1, 1};
    assert(solution.minOperations(nums) == -1);

    nums = {2, 3, 3, 2, 2, 4, 2, 3, 4};
    assert(solution.minOperations(nums) == 4);

    nums = {14, 12, 14, 14, 12, 14, 14, 12, 12, 12, 12, 14, 14, 12, 14, 14, 14, 12, 12};
    assert(solution.minOperations(nums) == 7);
    return 0;
}