#include <iostream>
#include <vector>
#include <set>
#include <assert.h>

class Solution
{
public:
    std::string destCity(std::vector<std::vector<std::string>> &paths)
    {
        std::set<std::string> dests;
        for (auto dest : paths)
            dests.insert(dest[1]);

        for (auto path : paths)
        {
            auto ind = dests.find(path[0]);
            if (ind != dests.end())
            {
                dests.erase(ind);
            }
        }

        return *dests.begin();
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    std::vector<std::vector<std::string>> arr = {{"London", "New York"}, {"New York", "Lima"}, {"Lima", "Sao Paulo"}};
    assert(solution.destCity(arr) == "Sao Paulo");

    arr = {{"pYyNGfBYbm", "wxAscRuzOl"}, {"kzwEQHfwce", "pYyNGfBYbm"}};
    assert(solution.destCity(arr) == "wxAscRuzOl");
    return 0;
}