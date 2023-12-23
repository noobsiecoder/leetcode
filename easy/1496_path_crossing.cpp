#include <iostream>
#include <vector>
#include <set>
#include <assert.h>

// Runtime: 0ms; Beats 100.00% of users with C++
// Memory:  7.40MB; Beats 7.18% of users with C++
class Solution
{
public:
    bool isPathCrossing(std::string path)
    {
        std::set<std::vector<int>> visited;
        int x = 0, y = 0;

        visited.insert({x, y});
        for (auto direction : path)
        {
            switch (direction)
            {
            case 'N':
                if (!visited.insert({x, ++y}).second)
                    return true;
                break;
            case 'E':
                if (!visited.insert({++x, y}).second)
                    return true;
                break;
            case 'W':
                if (!visited.insert({--x, y}).second)
                    return true;
                break;
            case 'S':
                if (!visited.insert({x, --y}).second)
                    return true;
                break;
            default:
                break;
            }
        }

        return false;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    std::cout << solution.isPathCrossing("NES") << std::endl;
    std::cout << solution.isPathCrossing("NESWW") << std::endl;
    std::cout << solution.isPathCrossing("NNSWWEWSSESSWENNW") << std::endl;

    return 0;
}