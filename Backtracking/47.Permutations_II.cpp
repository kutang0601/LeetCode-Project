#include <algorithm>
#include <vector>

class Solution 
{
public:
    std::vector<std::vector<int>> ret;
    std::vector<int> temp;

    void backtrace(std::vector<int>& nums, std::vector<bool>& judge)
    {
        if (nums.size() == temp.size())
        {
            ret.push_back(temp);
            return;
        }
        for (int n = 0; n < nums.size(); n++)
        {
            if (judge[n])
                continue;
            
            if (n > 0 && nums[n - 1] == nums[n] && !judge[n - 1])
                continue;

            temp.push_back(nums[n]);
            judge[n] = true;

            backtrace(nums, judge);

            temp.pop_back();
            judge[n] = false;
        }
    }

    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());

        std::vector<bool> judge(nums.size(), false);

        backtrace(nums, judge);

        return ret;
    }
};