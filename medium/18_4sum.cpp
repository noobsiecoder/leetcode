#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

// Runtime: 34ms; Beats 77.37% of users with C++
// Memory:  13.85MB; Beats 37.18% of users with C++
class Solution
{
public:
    std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target)
    {
        if (nums.size() < 4)
            return {};

        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> sums;

        for (size_t i = 0; i < nums.size() - 3; i++)
        {
            long long target_3 = (long long)target - (long long)nums[i];
            for (size_t j = i + 1; j < nums.size() - 2; j++)
            {
                long long target_2 = (long long)target_3 - (long long)nums[j];
                size_t low = j + 1, high = nums.size() - 1;
                while (low < high)
                {
                    int sum = nums[low] + nums[high];
                    if (sum < target_2)
                        ++low;
                    else if (sum > target_2)
                        --high;
                    else
                    {
                        std::vector<int> quadrant = {nums[i], nums[j], nums[low], nums[high]};
                        sums.push_back(quadrant);
                        ++low;
                        --high;

                        while (low < high && nums[low] == quadrant[2])
                            ++low;
                        while (low < high && nums[high] == quadrant[3])
                            --high;
                    }
                }
                while (j < nums.size() - 2 && nums[j] == nums[j + 1])
                    ++j;
            }
            while (i < nums.size() - 1 && nums[i] == nums[i + 1])
                ++i;
        }

        return sums;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    std::vector<int> nums = {1, 0, -1, 0, -2, 2};
    std::vector<std::vector<int>> expectedResult = {{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}};
    assert(solution.fourSum(nums, 0) == expectedResult);

    nums = {2, 2, 2, 2};
    expectedResult = {{2, 2, 2, 2}};
    assert(solution.fourSum(nums, 8) == expectedResult);

    nums = {-3, -2, -1, 0, 0, 1, 2, 3};
    expectedResult = {{-3, -2, 2, 3}, {-3, -1, 1, 3}, {-3, 0, 0, 3}, {-3, 0, 1, 2}, {-2, -1, 0, 3}, {-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}};
    assert(solution.fourSum(nums, 0) == expectedResult);

    return 0;
}