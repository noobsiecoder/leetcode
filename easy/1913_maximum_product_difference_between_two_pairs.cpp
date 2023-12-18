#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

// Runtime: 20ms; Beats 74.89% of users with C++
// Memory:  20.60MB; Beats 97.27% of users with C++
class Solution
{
public:
    int maxProductDifference(std::vector<int> &nums)
    {
        std::pair<int, int> max_pair = {INT16_MIN, INT16_MIN};
        std::pair<int, int> min_pair = {INT16_MAX, INT16_MAX};
        for (auto num : nums)
        {
            if (max_pair.first < num)
                max_pair.second = std::exchange(max_pair.first, num);
            else if (max_pair.second < num)
                max_pair.second = num;

            if (min_pair.first > num)
                min_pair.second = std::exchange(min_pair.first, num);
            else if (min_pair.second > num)
                min_pair.second = num;
        }

        return (max_pair.first * max_pair.second) - (min_pair.first * min_pair.second);
    }
};

int main(int argc, char *argv[])
{
    Solution solution;

    std::vector<int> nums = {5, 6, 2, 7, 4};
    assert(solution.maxProductDifference(nums) == 34);

    nums = {4, 2, 5, 9, 7, 4, 8};
    assert(solution.maxProductDifference(nums) == 64);

    nums = {8, 3, 5, 7};
    assert(solution.maxProductDifference(nums) == 41);
    return 0;
}