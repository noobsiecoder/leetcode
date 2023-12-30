#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <cassert>

// Runtime: 10ms; Beats85.99% of users with C++
// Memory:  12.61MB; Beats 21.01% of users with C++
class Solution
{
private:
    std::unordered_map<char, int> charFrequency;

public:
    bool makeEqual(std::vector<std::string> &words)
    {
        for (auto word : words)
        {
            for (auto letter : word)
            {
                ++charFrequency[letter];
            }
        }

        size_t arrSize = words.size();
        for (auto field : charFrequency)
        {
            if (field.second % arrSize != 0)
                return false;
        }

        return true;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    std::vector<std::string> words = {"abc", "aabc", "bc"};
    assert(solution.makeEqual(words));

    words = {"abc", "bc"};
    assert(!solution.makeEqual(words));
    return 0;
}
