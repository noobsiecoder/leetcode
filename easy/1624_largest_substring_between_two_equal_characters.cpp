#include <iostream>
#include <cstring>
#include <unordered_map>
#include <cassert>

// Runtime: 0ms; Beats 100.00% of users with C++
// Memory:  6.64MB; Beats 75.31% of users with C++
class Solution
{
private:
    std::unordered_map<char, size_t> previousCharIndex;

public:
    int maxLengthBetweenEqualCharacters(std::string s)
    {
        int result = -1;
        for (size_t i = 0; i < s.length(); i++)
        {
            char letter = s[i];
            if (previousCharIndex.count(letter) == 0)
            {
                previousCharIndex[letter] = i;
            }
            else
            {
                int distance = i - previousCharIndex[letter] - 1;
                result = std::max(result, distance);
            }
        }

        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    assert(solution.maxLengthBetweenEqualCharacters("aa") == 0);
    assert(solution.maxLengthBetweenEqualCharacters("abca") == 2);
    assert(solution.maxLengthBetweenEqualCharacters("abc") == -1);
    
    return 0;
}