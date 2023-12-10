#include <iostream>
#include <assert.h>

class Solution
{
private:
    void trim(std::string &s)
    {
        s.erase(0, s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ') + 1);
    }

public:
    int myAtoi(std::string s)
    {
        trim(s);
        long num = 0;
        if (s.empty())
            return num;

        int sign = s[0] == '-' ? -1 : 1;
        if (s[0] == '+' || s[0] == '-')
            s = s.substr(1);

        for (auto chr : s)
        {
            if (!isdigit(chr))
                break;
            num = num * 10 + (chr - '0');
            if (num * sign > INT32_MAX)
                return INT32_MAX;
            if (num * sign < INT32_MIN)
                return INT32_MIN;
        }

        return num * sign;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    assert(solution.myAtoi("42") == 42);
    assert(solution.myAtoi("3471") == 3471);
    assert(solution.myAtoi("3.14") == 3);
    assert(solution.myAtoi("  -42") == -42);
    assert(solution.myAtoi("4193 with words") == 4193);
    assert(solution.myAtoi("-91283472332") == INT32_MIN);
    return 0;
}