#include <iostream>
#include <vector>
#include <cassert>

// Runtime: 3ms; Beats 45.18% of users with C++
// Memory:  6.56MB; Beats 96.91% of users with C++
class Solution
{
public:
    bool isValid(std::string s)
    {
        std::vector<char> stack = {};
        for (auto chr : s)
        {
            if (chr == '(' || chr == '[' || chr == '{')
            {
                stack.push_back(chr);
                continue;
            }

            if (stack.empty())
                return false;

            char value = stack[stack.size() - 1];
            switch (chr)
            {
            case ')':
                if (value != '(')
                    return false;
                stack.pop_back();
                break;
            case ']':
                if (value != '[')
                    return false;
                stack.pop_back();
                break;
            case '}':
                if (value != '{')
                    return false;
                stack.pop_back();
                break;
            default:
                break;
            }
        }

        return stack.empty();
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    assert(solution.isValid("(){}[]"));
    assert(!solution.isValid("()}[]"));
    
    return 0;
}