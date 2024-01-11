#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

// Runtime: 126ms; Beats 83.54% of users with C++
// Memory:  69.43MB; Beats 74.15% of users with C++
struct Job
{
    int startTime;
    int endTime;
    int profit;
    Job(int startTime, int endTime, int profit)
        : startTime(startTime), endTime(endTime), profit(profit) {}
};

class Solution
{
private:
    std::vector<int> dp;

    int jobScheduling(const std::vector<Job> &jobs, const std::vector<int> &startTime, int i)
    {
        if (i == jobs.size())
            return 0;
        if (dp[i] > 0)
            return dp[i];

        const int j = firstGreaterEqual(startTime, i + 1, jobs[i].endTime);
        const int pick = jobs[i].profit + jobScheduling(jobs, startTime, j);
        const int skip = jobScheduling(jobs, startTime, i + 1);
        return dp[i] = std::max(pick, skip);
    }

    int firstGreaterEqual(const std::vector<int> &A, int startFrom, int target)
    {
        return std::lower_bound(A.begin() + startFrom, A.end(), target) - A.begin();
    }

public:
    int jobScheduling(std::vector<int> &startTime, std::vector<int> &endTime, std::vector<int> &profit)
    {
        const int n = startTime.size();
        // dp[i] = the maximum profit to schedule jobs[i..n)
        dp.resize(n + 1);
        std::vector<Job> jobs;

        for (int i = 0; i < n; ++i)
            jobs.emplace_back(startTime[i], endTime[i], profit[i]);

        std::sort(jobs.begin(), jobs.end(), [](const auto &a, const auto &b)
                  { return a.startTime < b.startTime; });

        // binary search to determine the 1st available startTime
        for (int i = 0; i < n; ++i)
            startTime[i] = jobs[i].startTime;

        return jobScheduling(jobs, startTime, 0);
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    std::vector<int> startTime = {1, 2, 3, 3};
    std::vector<int> endTime = {3, 4, 5, 6};
    std::vector<int> profits = {50, 10, 40, 70};
    assert(solution.jobScheduling(startTime, endTime, profits) == 120);
    return 0;
}