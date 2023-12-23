#include <iostream>
#include <vector>
#include <map>
#include <assert.h>

// Runtime: 0ms; Beats 100.00% of users with C++
// Memory:  7.06MB; Beats 25.16% of users with C++
class Solution
{
private:
    std::map<char, std::string> _numberLetterCombo;
    std::vector<std::string> _combination;

    void backTrack(size_t index, std::string value, std::string digits)
    {
        if (value.length() == digits.length())
        {
            _combination.push_back(value);
            return;
        }

        for (auto chr : _numberLetterCombo[digits[index]])
        {
            backTrack(index + 1, value + chr, digits);
        }
    }

public:
    Solution()
    {
        _numberLetterCombo['2'] = "abc";
        _numberLetterCombo['3'] = "def";
        _numberLetterCombo['4'] = "ghi";
        _numberLetterCombo['5'] = "jkl";
        _numberLetterCombo['6'] = "mno";
        _numberLetterCombo['7'] = "pqrs";
        _numberLetterCombo['8'] = "tuv";
        _numberLetterCombo['9'] = "wxyz";
    }

    std::vector<std::string> letterCombinations(std::string digits)
    {
        if (digits.empty())
        {
            _combination.clear(); // Clear the vector if digits is empty
            return {};
        }

        _combination.clear(); // Clear the vector before populating it
        backTrack(0, "", digits);
        return _combination;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    assert(solution.letterCombinations("23") == std::vector<std::string>({"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}));
    assert(solution.letterCombinations("") == std::vector<std::string>({}));

    return 0;
}