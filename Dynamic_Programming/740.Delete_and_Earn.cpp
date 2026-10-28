
#include <vector>
#include <algorithm>

class Solution
{
    public:
        int deleteAndEarn(std::vector<int>& nums)
        {
            if (nums.empty())
                return 0;

            int max_value = *std::max_element(nums.begin(), nums.end());

            std::vector<int> points(max_value + 1, 0);

            for (size_t i = 0; i < nums.size(); i++)
            {
                points[nums[i]] += nums[i];
            }

            std::vector<int> dp(max_value + 1, 0);

            dp[1] = points[1];

            for (int i = 2; i <= max_value; i++)
            {
                dp[i] = std::max(dp[i - 1], dp[i - 2] + points[i]);
            }

            return dp[max_value];
        }
};
