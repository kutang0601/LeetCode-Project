#include <algorithm>
#include <vector>

class Solution 
{
public:
    int longestConsecutive(std::vector<int>& nums) 
    {
        if (nums.empty())
            return 0;

        std::sort(nums.begin(), nums.end());

        int ret = 1;
        int temp = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                continue;
            }

            if (nums[i] == nums[i - 1] + 1)
            {
                temp++;
            }
            else
            {
                ret = std::max(ret, temp);
                temp = 1;
            }
        }

        ret = std::max(ret, temp);

        return ret;
    }
};