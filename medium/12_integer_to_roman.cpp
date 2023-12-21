#include <iostream>
#include <vector>
#include <assert.h>

// Runtime: 11ms; Beats 28.30% of users with C++
// Memory:  9.18MB; Beats 37.65% of users with C++
class Solution
{
private:
    std::vector<int> intNumbers;
    std::vector<std::string> romanNumbers;

public:
    Solution()
    {
        intNumbers = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        romanNumbers = {"M",
                        "CM",
                        "D",
                        "CD",
                        "C",
                        "XC",
                        "L",
                        "XL",
                        "X",
                        "IX",
                        "V",
                        "IV",
                        "I"};
    }

    std::string intToRoman(int num)
    {
        std::string roman = "";
        for (size_t i = 0; i < intNumbers.size(); i++)
        {
            while (intNumbers[i] <= num)
            {
                num -= intNumbers[i];
                roman += romanNumbers[i];
            }
        }

        return roman;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    assert(solution.intToRoman(36) == "XXXVI");
    assert(solution.intToRoman(1994) == "MCMXCIV");
    return 0;
}