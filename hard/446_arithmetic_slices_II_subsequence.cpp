#include <cassert>
#include <iostream>
#include <map>
#include <vector>

// Runtime: 622ms; Beats 47.50% of users with C++
// Memory:  115.56MB; Beats 72.22% of users with C++
class Solution
{
public:
    int numberOfArithmeticSlices(std::vector<int> &nums)
    {
        long long totalArithmeticSlices = 0;
        std::vector<std::map<int, int>> diffFrequency(nums.size());
        for (size_t i = 1; i < nums.size(); i++)
        {
            for (size_t j = 0; j < i; j++)
            {
                long long difference = (long long)nums[i] - (long long)nums[j];
                if (difference <= INT32_MIN || difference >= INT32_MAX)
                    continue;

                int tempSequence = 0;
                if (diffFrequency[j].find(difference) != diffFrequency[j].end())
                    tempSequence = diffFrequency[j][difference];

                diffFrequency[i][difference] += tempSequence + 1;
                totalArithmeticSlices += tempSequence;
            }
        }

        return (int)totalArithmeticSlices;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    std::vector<int> nums = {2, 4, 6, 8, 10};
    assert(solution.numberOfArithmeticSlices(nums) == 7);

    nums = {7, 7, 7, 7, 7};
    assert(solution.numberOfArithmeticSlices(nums) == 16);
    return 0;
}