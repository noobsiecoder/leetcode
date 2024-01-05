#include <iostream>
#include <vector>
#include <cassert>

// Runtime: 232ms; Beats 62.00% of users with C++
// Memory:  10.84MB; Beats 62.11% of users with C++
class Solution
{
public:
    int lengthOfLIS(std::vector<int> &nums)
    {
        std::vector<int> dp(nums.size());
        std::fill(dp.begin(), dp.end(), 1);
        int max = INT16_MIN;

        if (nums.size() == 1)
            return 1;

        for (size_t i = 1; i < nums.size(); i++)
        {
            for (size_t j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                    }
                }
            }
            max = std::max(dp[i], max);
        }

        return max;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    std::vector<int> nums = {0, 1, 0, 3, 2, 3};
    assert(solution.lengthOfLIS(nums) == 4);

    nums = {10, 9, 2, 5, 3, 7, 101, 18};
    assert(solution.lengthOfLIS(nums) == 4);

    nums = {7, 7, 7, 7, 7};
    assert(solution.lengthOfLIS(nums) == 1);

    nums = {7};
    assert(solution.lengthOfLIS(nums) == 1);
    return 0;
}