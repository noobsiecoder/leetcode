#include <iostream>
#include <assert.h>

class Solution
{
public:
    int totalMoney(int n)
    {
        int amount = 0;
        int week_start_value = 1;
        for (size_t i = 0, j = 0; i < n; i++, j++)
        {
            if (i % 7 == 0 && i != 0)
            {
                week_start_value += 1;
                j = 0;
            }
            amount += week_start_value + (int)j;
        }

        return amount;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    assert(solution.totalMoney(4) == 10);
    assert(solution.totalMoney(7) == 28);
    assert(solution.totalMoney(13) == 55);
    assert(solution.totalMoney(20) == 96);

    return 0;
}