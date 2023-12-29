#include <iostream>
#include <vector>

// Runtime: 22ms; Beats 79.04% of users with C++
// Memory:  8.18MB; Beats 33.73% of users with C++
class Solution
{
private:
    size_t arrSize;
    int getMaxValue(std::vector<int> &jobDifficulty, size_t startIdx)
    {
        int max = INT16_MIN;
        for (size_t i = startIdx; i < arrSize; i++)
            max = std::max(max, jobDifficulty[i]);

        return max;
    }

public:
    int minDifficulty(std::vector<int> &jobDifficulty, int d)
    {
        arrSize = jobDifficulty.size();
        if (arrSize < d)
        {
            return -1;
        }

        std::vector<std::vector<int>> dp(arrSize + 1, std::vector<int>(d + 1, -1));
        for (int i = 0; i < arrSize; i++)
        {
            dp[i][1] = getMaxValue(jobDifficulty, i);
        }

        for (size_t i = 2; i <= d; i++)
        {
            for (size_t j = 0; j <= arrSize - i; j++)
            {
                int maxDifficulty = INT16_MIN;
                int result = INT16_MAX;

                for (int k = j; k <= arrSize - i; k++)
                {
                    maxDifficulty = std::max(maxDifficulty, jobDifficulty[k]);
                    result = std::min(result, maxDifficulty + dp[k + 1][i - 1]);
                }

                dp[j][i] = result;
            }
        }

        return dp[0][d];
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    std::vector<int> jobDifficulties = {9, 9, 9};
    std::cout << solution.minDifficulty(jobDifficulties, 4) << std::endl;

    jobDifficulties = {1, 1, 1};
    std::cout << solution.minDifficulty(jobDifficulties, 3) << std::endl;

    jobDifficulties = {6, 5, 4, 3, 2, 1};
    std::cout << solution.minDifficulty(jobDifficulties, 2) << std::endl;
    return 0;
}