#include <iostream>
#include <vector>
#include <unordered_map>
#include <assert.h>

// Runtime: 218ms; Beats 5.02% of users with C++
// Memory:  83.22MB; Beats 5.35% of users with C++
class Solution
{
private:
    bool checkIfCharCanBeUsed(std::unordered_map<char, int> char_map, std::string word)
    {
        std::unordered_map<char, int> copy_char_map = char_map;
        for (auto chr : word)
        {
            if (--copy_char_map[chr] < 0)
                return false;
        }

        return true;
    }

public:
    int countCharacters(std::vector<std::string> &words, std::string chars)
    {
        std::unordered_map<char, int> char_map;
        for (auto chr : chars)
        {
            ++char_map[chr];
        }

        int sum = 0;
        for (auto word : words)
        {
            if (checkIfCharCanBeUsed(char_map, word))
                sum += word.length();
        }

        return sum;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    std::vector<std::string> words = {"cat", "bt", "hat", "tree"};
    assert(solution.countCharacters(words, "atach") == 6);
    words = {"hello", "world", "leetcode"};
    assert(solution.countCharacters(words, "welldonehoneyr") == 10);

    return 0;
}