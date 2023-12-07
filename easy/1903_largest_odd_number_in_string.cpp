#include <iostream>
#include <assert.h>

class Solution
{
public:
    std::string largestOddNumber(std::string num)
    {
        size_t size = num.length();
        std::string largest_odd_value = "";

        for (int i = size - 1; i >= 0; i--)
        {
            if ((int)num[i] % 2 != 0)
            {
                largest_odd_value = num.substr(0, i + 1);
                break;
            }
        }
        return largest_odd_value;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    assert(solution.largestOddNumber("52") == "5");
    assert(solution.largestOddNumber("5230456") == "523045");
    assert(solution.largestOddNumber("520453") == "520453");
    assert(solution.largestOddNumber("132321") == "132321");
    return 0;
}