#include <iostream>

class Solution
{
public:
    std::string largestOddNumber(std::string num)
    {
        size_t size = num.length();
        if (size <= 1)
            return "";

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
    std::cout << solution.largestOddNumber("52") << std::endl;
    std::cout << solution.largestOddNumber("5230456") << std::endl;
    std::cout << solution.largestOddNumber("520453") << std::endl;
    std::cout << solution.largestOddNumber("132321") << std::endl;
    return 0;
}