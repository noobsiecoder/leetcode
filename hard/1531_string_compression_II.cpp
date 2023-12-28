#include <iostream>
#include <vector>
#include <cassert>

class Solution
{
private:
    int strSize;
    std::vector<std::vector<int>> values;

    int dp(int idx, int k, std::string s)
    {
        if (k < 0)
            return INT16_MAX;

        if (idx >= strSize || (strSize - idx) <= k)
            return 0;

        if (values[idx][k] != -1)
            return values[idx][k];

        int deleted_idx = dp(idx + 1, k - 1, s);
        int keep_idx = INT16_MAX;

        int deleted = 0;
        int charFrequency = 0;
        int addition = 0;

        for (size_t j = idx; j < s.length() && deleted <= k; j++)
        {
            if (s[j] == s[idx])
            {
                ++charFrequency;
                if (charFrequency == 2 || charFrequency == 10 || charFrequency == 100)
                {
                    ++addition;
                }
            }
            else
            {
                ++deleted;
            }

            keep_idx = std::min(keep_idx, 1 + addition + dp(j + 1, k - deleted, s));
        }

        values[idx][k] = std::min(deleted_idx, keep_idx);
        return values[idx][k];
    }

public:
    int getLengthOfOptimalCompression(std::string s, int k)
    {
        strSize = s.length();
        values = std::vector<std::vector<int>>(strSize + 1, std::vector<int>(k + 1, -1));
        return dp(0, k, s);
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    assert(solution.getLengthOfOptimalCompression("aaabcccd", 2) == 4);

    return 0;
}