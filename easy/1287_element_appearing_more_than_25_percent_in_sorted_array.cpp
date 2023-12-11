#include <iostream>
#include <vector>
#include <assert.h>

class Solution
{
public:
    int findSpecialInteger(std::vector<int> &arr)
    {
        size_t arr_size = arr.size();
        int twenty_five_percent = (int)arr_size / 4;
        for (size_t i = 0; i < arr_size; i++)
        {
            if (arr[i] == arr[i + twenty_five_percent])
            {
                return arr[i];
            }
        }

        return -1;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    std::vector<int> arr = {1, 2, 2, 6, 6, 6, 6, 7, 10};
    assert(solution.findSpecialInteger(arr) == 6);
    arr = {1, 1};
    assert(solution.findSpecialInteger(arr) == 1);
    
    return 0;
}