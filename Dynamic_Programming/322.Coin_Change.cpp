#include <vector>
#include <algorithm>

//dp[i]表示i元需要最少多少硬币兑换
//时间复杂度：O(amount * n)
class Solution 
{
public:
    int coinChange(std::vector<int>& coins, int amount) 
    {
        std::vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0;

        for (int n = 1; n < amount + 1; n++)
        {
            for (int m = 0; m < coins.size(); m++)
            {
                if (n >= coins[m])
                {
                    dp[n] = std::min(dp[n], dp[n - coins[m]] + 1);
                }
            }
        }

        if (dp[amount] == amount + 1)
        {
            return -1;
        }

        return dp.back();
    }
};