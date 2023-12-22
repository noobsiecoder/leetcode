#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <assert.h>

// Runtime: 35ms; Beats 69.28% of users with C++
// Memory:  10.62MB; Beats 23.09% of users with C++
class Solution
{
public:
    int threeSumClosest(std::vector<int> &nums, int target)
    {
        std::sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];
        int difference = INT16_MAX;

        for (size_t i = 0; i < nums.size() - 2; i++)
        {
            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target)
                    return sum;
                else if (sum < target)
                    ++j;
                else
                    --k;

                int targetDiff = abs(sum - target);
                if (targetDiff < difference)
                {
                    closestSum = sum;
                    difference = targetDiff;
                }
            }
        }

        return closestSum;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;

    std::vector<int> nums = {-1, 2, 1, -4};
    assert(solution.threeSumClosest(nums, 1) == 2);

    nums = {0, 0, 0};
    assert(solution.threeSumClosest(nums, 1) == 0);

    nums = {-1, 0, 1, 2, -1, -4};
    assert(solution.threeSumClosest(nums, 4) == 3);
    return 0;
}
