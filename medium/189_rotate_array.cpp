#include <vector>
#include <cassert>

// Runtime: 18ms; Beats 77.31% of users with C++
// Memory:  27.49MB; Beats 65.09% of users with C++
class Solution
{
public:
    void rotate(std::vector<int> &nums, int k)
    {
        std::size_t nums_size = nums.size();
        // edge case
        // handle when k > nums.length
        k %= nums_size;

        // reverse the array
        // Time:    O(n)
        // Space:   O(1)
        for (std::size_t i = 0; i < nums_size / 2; i++)
        {
            int temp = nums[i];
            nums[i] = nums[nums_size - i - 1];
            nums[nums_size - i - 1] = temp;
        }

        // reverse the values in the array from 0..k
        // Time:    O(k)
        // Space:   O(1)
        for (std::size_t i = 0; i < k / 2; i++)
        {
            int temp = nums[i];
            nums[i] = nums[k - i - 1];
            nums[k - i - 1] = temp;
        }

        // reverse the values in the array from k..n
        // Time:    O(n - k)
        // Space:   O(1)
        for (std::size_t i = 0; i < (nums_size - k) / 2; i++)
        {
            int temp = nums[i + k];
            nums[i + k] = nums[nums_size - i - 1];
            nums[nums_size - i - 1] = temp;
        }
    }
};

int main(int argv, char **argc)
{
    Solution solution = Solution();
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> target = {5, 6, 7, 1, 2, 3, 4};
    solution.rotate(arr, 3);
    assert(arr == target);

    target = {2, 3, 4, 5, 6, 7, 1};
    solution.rotate(arr, 3);
    assert(arr == target);

    arr = {-1, -100, 3, 99};
    target = {3, 99, -1, -100};
    solution.rotate(arr, 2);
    assert(arr == target);

    arr = {1, 2};
    target = {2, 1};
    solution.rotate(arr, 3);
    assert(arr == target);
}