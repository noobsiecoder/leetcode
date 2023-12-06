#include <iostream>
#include <assert.h>

class Solution
{
public:
    std::string longestPalindrome(std::string s)
    {
        if (s.empty())
            return s;
        size_t max_len = 1;
        size_t str_size = s.length();
        int start = 0, end = 0;

        for (size_t i = 0; i < str_size - 1; ++i)
        {
            // Odd length
            int left = i, right = i;
            while (left >= 0 && right < str_size && s[left] == s[right])
            {
                left--;
                right++;
            }
            if (right - left - 1 > max_len)
            {
                max_len = right - left - 1;
                start = left + 1;
                end = right - 1;
            }

            // Even length
            left = i, right = i + 1;
            while (left >= 0 && right < str_size && s[left] == s[right])
            {
                left--;
                right++;
            }
            if (right - left - 1 > max_len)
            {
                max_len = right - left - 1;
                start = left + 1;
                end = right - 1;
            }
        }

        return s.substr(start, max_len);
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    assert(solution.longestPalindrome("babad") == "bab");
    assert(solution.longestPalindrome("cbbd") == "bb");
    assert(solution.longestPalindrome("abacaba") == "abacaba");
    assert(solution.longestPalindrome("pilot") == "p");
    return 0;
}