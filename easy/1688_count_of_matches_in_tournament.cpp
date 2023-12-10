#include <iostream>

class Solution
{
public:
    int numberOfMatches(int n)
    {
        int matches = 0;
        while (n != 1)
        {
            if (n % 2 == 0)
            {
                matches += n / 2;
                n /= 2;
            }
            else
            {
                matches += (n - 1) / 2;
                n = ((n - 1) / 2) + 1;
            }
        }

        return matches;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    std::cout << solution.numberOfMatches(7) << std::endl;
    std::cout << solution.numberOfMatches(14) << std::endl;
    return 0;
}