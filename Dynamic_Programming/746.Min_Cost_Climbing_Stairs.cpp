#include <vector>
#include <algorithm>

class Solution
{
public:
    int minCostClimbingStairs(std::vector<int>& cost)
    {
        std::vector<int> dp(cost.size() + 1, 0);

        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i < cost.size() + 1; i++)
        {
            dp[i] = std::min(dp[i - 1] + cost[i - 1],
                             dp[i - 2] + cost[i - 2]);
        }

        return dp.back();
    }
};
