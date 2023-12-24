#include <iostream>
#include <cassert>

// Runtime: 3ms; Beats 78.34% of users with C++
// Memory:  7.27MB; Beats 86.65% of users with C++
class Solution
{
public:
    int minOperations(std::string s)
    {
        int operation10 = 0; // for 1001 to 1010
        for (size_t i = 0; i < s.length(); i++)
        {
            if (s[i] - '0' == i % 2)
                ++operation10;
        }

        int operation01 = s.length() - operation10; // for 0100 to 0101
        return std::min(operation10, operation01);
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    assert(solution.minOperations("0100") == 1);
    assert(solution.minOperations("1001") == 2);

    return 0;
}