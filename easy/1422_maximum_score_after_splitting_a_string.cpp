#include <iostream>
#include <algorithm>

// Runtime: 0ms; Beats 100.00% of users with C++
// Memory:  6.75MB; Beats 43.75% of users with C++
class Solution
{
public:
    int maxScore(std::string s)
    {
        int maxValue = 0;
        int zeros = 0;
        int ones = std::count(s.begin(), s.end(), '1');
        for (size_t i = 0; i < s.length() - 1; i++)
        {
            if (s[i] == '0')
                ++zeros;
            else
                --ones;

            maxValue = std::max(maxValue, zeros + ones);
        }

        return maxValue;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    std::cout << solution.maxScore("011101") << std::endl;
    std::cout << solution.maxScore("00111") << std::endl;
    std::cout << solution.maxScore("1111") << std::endl;

    return 0;
}