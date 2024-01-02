#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

// Runtime: 16ms; Beats 32.20% of users with C++
// Memory:  30.41MB; Beats 26.85% of users with C++
class Solution
{
private:
    std::unordered_map<int, int> numberFrequency;

public:
    std::vector<std::vector<int>> findMatrix(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> uniqueNums;
        for (size_t i = 0; i < nums.size(); i++)
        {
            ++numberFrequency[nums[i]];
            if (uniqueNums.size() < numberFrequency[nums[i]])
                uniqueNums.push_back({});

            uniqueNums.at(numberFrequency[nums[i]] - 1).push_back(nums[i]);
        }

        return uniqueNums;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    std::vector<int> nums = {1, 3, 4, 1, 2, 3};
    assert(solution.findMatrix(nums) == std::vector<std::vector<int>>({{1, 3, 4, 2}, {1, 3}}));

    return 0;
}