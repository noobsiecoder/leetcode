#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

// Runtime: 20ms; Beats 74.89% of users with C++
// Memory:  20.60MB; Beats 97.27% of users with C++
class Solution
{
public:
    int maxProduct(std::vector<int> &nums)
    {
        int max1 = 0;
        int max2 = 0;
        for (const int num : nums)
        {
            if (num > max1)
                max2 = std::exchange(max1, num);
            else if (num > max2)
                max2 = num;
        }

        return (max1 - 1) * (max2 - 1);
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    std::vector<int> arr = {3, 4, 5, 2};
    assert(solution.maxProduct(arr) == 34);

    arr = {1, 5, 4, 5};
    assert(solution.maxProduct(arr) == 64);

    arr = {3, 7};
    assert(solution.maxProduct(arr) == 41);

    return 0;
}