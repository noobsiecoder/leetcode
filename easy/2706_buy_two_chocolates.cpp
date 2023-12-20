#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

// Runtime: 12ms; Beats 59.66% of users with C++
// Memory:  46.96MB; Beats 58.30% of users with C++
class Solution
{
public:
    int buyChoco(std::vector<int> &prices, int money)
    {
        int min_1 = INT16_MAX;
        int min_2 = INT16_MAX;
        for (auto price : prices)
        {
            if (min_1 > price)
            {
                min_2 = std::exchange(min_1, price);
            }
            else if (min_2 > price)
            {
                min_2 = price;
            }
        }

        int sum = money - (min_1 + min_2);

        return sum >= 0 ? sum : money;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;

    std::vector<int> prices = {1, 2, 2};
    assert(solution.buyChoco(prices, 3) == 0);

    prices = {3, 2, 3};
    assert(solution.buyChoco(prices, 3) == 3);

    prices = {98, 54, 6, 34, 66, 63, 52, 39};
    assert(solution.buyChoco(prices, 62) == 22);
    return 0;
}