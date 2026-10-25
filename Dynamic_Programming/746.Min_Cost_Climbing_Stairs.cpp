#include <algorithm>
#include <vector>

//动态规划，dp[i] 代表到达位置 i 所需要的最少费用
//到达 i 有两种可能，一种是从前一个走，支付走路的费用，另一种是从前两个走，支付走路费用
//时间复杂度：O(n)
class Solution 
{
public:
    int minCostClimbingStairs(std::vector<int>& cost) 
    {
        std::vector<int> dp(cost.size() + 1, 0);

        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i <= cost.size(); i++)
        {
            dp[i] = std::min(cost[i - 2] + dp[i - 2], cost[i - 1] + dp[i - 1]);
        }

        return dp.back();
    }
};