#include <iostream>
#include <unordered_map>
#include <assert.h>

// Runtime: 11ms; Beats 45.06% of users with C++
// Memory:  7.85MB; Beats 20.94% of users with C++
class Solution
{
private:
    void build_map(std::unordered_map<char, int> &map, std::string str)
    {
        for (auto chr : str)
        {
            map[chr]++;
        }
    }

public:
    bool isAnagram(std::string s, std::string t)
    {
        if (s.length() != t.length())
            return false;

        std::unordered_map<char, int> str1;
        build_map(str1, s);

        for (auto chr : t)
        {
            str1[chr]--;
            if (str1[chr] < 0)
                return false;
        }

        return true;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    assert(solution.isAnagram("anagram", "nagaram"));
    assert(!solution.isAnagram("rat", "cat"));
    assert(!solution.isAnagram("a", "ab"));
    assert(!solution.isAnagram("aacc", "ccac"));

    return 0;
}