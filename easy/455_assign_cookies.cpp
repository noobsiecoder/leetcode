#include <iostream>
#include <vector>
#include <algorithm>

// Runtime: 23ms; Beats 61.11% of users with C++
// Memory:  17.74MB; Beats 75.56% of users with C++
class Solution
{
public:
    int findContentChildren(std::vector<int> &g, std::vector<int> &s)
    {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        size_t childrenIdx = 0;
        size_t cookieSizeIdx = 0;
        int maxCookies = 0;
        while (childrenIdx < g.size() && cookieSizeIdx < s.size())
        {
            if (g[childrenIdx] <= s[cookieSizeIdx])
            {
                ++childrenIdx;
                ++cookieSizeIdx;
                ++maxCookies;
            }
            else
            {
                ++cookieSizeIdx;
            }
        }

        return maxCookies;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    std::vector<int> children = {1, 2, 3};
    std::vector<int> cookieSize = {1, 1};
    std::cout << solution.findContentChildren(children, cookieSize) << std::endl;

    children = {1, 2};
    cookieSize = {1, 2, 3};
    std::cout << solution.findContentChildren(children, cookieSize) << std::endl;

    return 0;
}