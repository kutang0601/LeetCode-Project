
#include <vector>
#include <algorithm>

class Solution
{
public:
    int findNumberOfLIS(std::vector<int>& nums)
    {
        int size = nums.size();

        std::vector<int> dp(size, 1);
        std::vector<int> count(size, 1);

        int max_length = 1;

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                    else if (dp[j] + 1 == dp[i])
                    {
                        count[i] += count[j];
                    }
                }
            }

            max_length = std::max(max_length, dp[i]);
        }

        int ret = 0;

        for (int i = 0; i < size; i++)
        {
            if (dp[i] == max_length)
            {
                ret += count[i];
            }
        }

        return ret;
    }
};
