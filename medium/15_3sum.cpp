#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <assert.h>

// Runtime: 136ms; Beats 53.85% of users with C++
// Memory:  29.83MB; Beats 43.39% of users with C++
class Solution
{
private:
    std::map<int, int> complements;
    std::vector<std::vector<int>> triplets;
    const int TARGET = 0;

public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        if (nums[0] > 0)
            return triplets;

        for (size_t i = 0; i < nums.size(); i++)
        {
            // nums[i] + nums[j] + nums[k] = 0
            // nums[j] + nums[k] = -nums[i]
            int target = -nums[i];
            size_t j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                if (nums[j] + nums[k] == target)
                {
                    std::vector<int> triplet = {nums[i], nums[j], nums[k]};
                    triplets.push_back(triplet);
                    while (j < k && nums[j] == triplet[1])
                        j++;
                    while (j < k && nums[k] == triplet[2])
                        k--;
                }
                else if (nums[j] + nums[k] < target)
                    j++;
                else
                    k--;
            }
            while (i < nums.size() - 1 && nums[i] == nums[i + 1])
                i++;
        }

        return triplets;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;

    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> result = {{-1, -1, 2}, {-1, 0, 1}};
    assert(solution.threeSum(nums) == result);

    return 0;
}
