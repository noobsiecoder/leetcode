#include <cassert>
#include <iostream>
#include <string>
#include <vector>

// Runtime: 85ms; Beats 76.99% of users with C++
// Memory:  34.94MB; Beats 5.06% of users with C++
class Solution
{
private:
    int countOnes(std::string devices)
    {
        int count = 0;
        for (char value : devices)
        {
            if (value == '1')
                ++count;
        }

        return count;
    }

public:
    int numberOfBeams(std::vector<std::string> &bank)
    {
        int laserBeams = 0;
        int prevs = 0;

        for (std::string devices : bank)
        {
            int deviceCount = countOnes(devices);
            if (deviceCount > 0)
            {
                laserBeams += prevs * deviceCount;
                prevs = deviceCount;
            }
        }

        return laserBeams;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    std::vector<std::string> securityDevices = {"011001", "000000", "010100", "001000"};
    assert(solution.numberOfBeams(securityDevices) == 8);
    
    return 0;
}