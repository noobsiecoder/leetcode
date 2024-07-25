#include <iostream>
#include <vector>
#include <cassert>

// Sort performed: Merge
//
// Depth(x):
// n / (2 ^ x)  = 1 -> Taking log on both sides
// log(n)       = x
//
// Height(h):
// h = n
//
// Time Complexity:
// O(x * h) = O(nlog(n))

// Runtime: 377ms; Beats 36.84% of users with C++
// Memory:  178.37MB; Beats 28.80% of users with C++
class Solution
{
private:
    void merge_array(std::vector<int> &nums, size_t left_idx, size_t pivot, size_t right_idx)
    {
        std::vector<int> left = std::vector<int>(nums.begin() + left_idx, nums.begin() + pivot + 1);
        std::vector<int> right = std::vector<int>(nums.begin() + pivot + 1, nums.begin() + right_idx + 1);
        size_t i = left_idx;
        size_t j = 0;
        size_t k = 0;

        while (j < left.size() && k < right.size())
        {
            if (left[j] <= right[k])
            {
                nums[i++] = left[j++];
            }
            else
            {
                nums[i++] = right[k++];
            }
        }
        while (j < left.size())
        {
            nums[i++] = left[j++];
        }
        while (k < right.size())
        {
            nums[i++] = right[k++];
        }
    }

    void merge_sort(std::vector<int> &nums, size_t left_idx, size_t right_idx)
    {
        if (left_idx >= right_idx)
        {
            return;
        }

        size_t pivot = (left_idx + right_idx) / 2;
        merge_sort(nums, left_idx, pivot);
        merge_sort(nums, pivot + 1, right_idx);
        merge_array(nums, left_idx, pivot, right_idx);
    }

public:
    std::vector<int> sortArray(std::vector<int> &nums)
    {
        merge_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main(int argv, char **args)
{
    std::vector<int> vec = {5, 1, 4, 2};
    std::vector<int> test_vec = {1, 2, 4, 5};

    Solution *solution = new Solution();
    auto sorted_vec = solution->sortArray(vec);
    assert(sorted_vec == test_vec);
}