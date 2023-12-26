#include <iostream>
#include <set>
#include <cmath>
#include <vector>
#include <cassert>

// Runtime: 51ms; Beats 15.95% of users with C++
// Memory:  8.75MB; Beats 65.29% of users with C++
class Solution
{
private:
    const long MOD = pow(10, 9) + 7;

public:
    int numRollsToTarget(int n, int k, int target)
    {
        std::vector<int> targets(target + 1);
        std::fill(targets.begin(), targets.end(), 0);
        targets[0] = 1;

        for (size_t i = 0; i < n; i++)
        {
            std::vector<int> numTargets(target + 1);
            std::fill(numTargets.begin(), numTargets.end(), 0);
            for (size_t j = 1; j < k + 1; j++)
            {
                for (size_t x = j; x < target + 1; x++)
                {
                    numTargets[x] = (numTargets[x] + targets[x - j]) % MOD;
                }
            }
            targets = numTargets;
        }

        return targets[target];
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    assert(solution.numRollsToTarget(1, 6, 3) == 1);
    assert(solution.numRollsToTarget(2, 6, 7) == 6);

    return 0;
}