#include <algorithm>
#include <vector>

//动态规划，dp[i]代表总共i家最多可以偷多少
//时间复杂度：O(n)
class Solution 
{
public:
    int rob(std::vector<int>& nums) 
    {
        std::vector<int> dp(nums.size(), 0) ; 
        
        if (nums.size() <= 1)
        {
            return nums.back();
        }

        if (nums.size() == 2)
        {
            return std::max(nums[0], nums[1]);
        }

        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);
 
        for (int n = 2; n < nums.size(); n++)
        {
            dp[n] = std::max(dp[n - 1], dp[n - 2] + nums[n]);
        }

        return dp.back();
    }
};