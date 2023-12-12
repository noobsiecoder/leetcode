#include <iostream>
#include <vector>
#include <algorithm>

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
    std::cout << solution.maxProduct(arr) << std::endl;

    arr = {1, 5, 4, 5};
    std::cout << solution.maxProduct(arr) << std::endl;

    arr = {3, 7};
    std::cout << solution.maxProduct(arr) << std::endl;

    return 0;
}