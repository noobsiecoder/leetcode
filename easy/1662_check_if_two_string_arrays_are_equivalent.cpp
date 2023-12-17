#include <iostream>
#include <vector>

// Runtime: 0ms; Beats 100.00% of users with C++
// Memory:  11.52MB; Beats 99.04% of users with C++
class Solution
{
public:
    bool arrayStringsAreEqual(std::vector<std::string> &word1, std::vector<std::string> &word2)
    {
        size_t i = 0;
        size_t j = 0;
        size_t a = 0;
        size_t b = 0;

        while (i < word1.size() && j < word2.size())
        {
            if (word1[i][a] != word2[j][b])
                return false;
            if (++a == word1[i].size())
            {
                ++i;
                a = 0;
            }
            if (++b == word2[j].size())
            {
                ++j;
                b = 0;
            }
        }

        return i == word1.size() && j == word2.size();
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    std::vector<std::string> arr1 = {"ab", "c"};
    std::vector<std::string> arr2 = {"a", "bc"};
    std::cout << solution.arrayStringsAreEqual(arr1, arr2) << std::endl;

    arr1 = {"a", "cb"};
    arr2 = {"a", "bc"};
    std::cout << solution.arrayStringsAreEqual(arr1, arr2) << std::endl;

    arr1 = {"abc", "d", "defg"};
    arr2 = {"abcddefg"};
    std::cout << solution.arrayStringsAreEqual(arr1, arr2) << std::endl;
    return 0;
}