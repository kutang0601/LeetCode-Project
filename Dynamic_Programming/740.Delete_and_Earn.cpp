#include <algorithm>
#include <vector>

//动态规划，将nums整合为count，记录其每个数字删除能得到的点数，因为相同的数字之间不互相影响
//然后定义 dp[i] 为第 i 个数字的时候能够拿到的最多的点数，其中删除 i 就不能删除的它相邻的两个，所以判断dp[i - 1] 和 dp[i - 2] + count[i] 那个更大
//时间复杂度：O(n + max_count)
class Solution {
public:
    int deleteAndEarn(std::vector<int>& nums) 
    {
        if (nums.size() <= 1)
        {
            return nums.back();
        }

        int max_count = *std::max_element(nums.begin(), nums.end());

        std::vector<int> dp(max_count + 1, 0) ; 
        std::vector<int> count(max_count + 1, 0);

        for (int i = 0; i < nums.size(); i++)
        {
            count[nums[i]] += nums[i];
        }

        dp[1] = count[1];

        for (int n = 2; n < count.size(); n++)
        {
            dp[n] = std::max(dp[n - 1], dp[n - 2] + count[n]);
        }

        return dp.back(); 
    }
};