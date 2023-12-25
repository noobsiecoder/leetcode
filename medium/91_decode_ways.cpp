#include <iostream>
#include <vector>
#include <cassert>

// Runtime: 0ms; Beats 100.00% of users with C++
// Memory:  6.79MB; Beats 34.07% of users with C++
class Solution
{
public:
    int numDecodings(std::string s)
    {
        if (s[0] == '0')
            return 0;

        size_t size = s.length();
        std::vector<int> stack(size + 1);

        stack[0] = 1;
        stack[1] = 1;

        for (size_t i = 2; i <= size; i++)
        {
            stack[i] = 0;
            if (s[i - 1] > '0')
                stack[i] = stack[i - 1];
            if (s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] < '7')
                stack[i] += stack[i - 2];
        }

        return stack[size];
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    assert(solution.numDecodings("11106") == 2);
    // assert(solution.numDecodings("12") == 2);
    // assert(solution.numDecodings("226") == 3);
    assert(solution.numDecodings("06") == 0);

    return 0;
}