#include <vector>

class Solution 
{
    public:
        std::vector<std::vector<int>> ret;
        std::vector<int> temp;

        void backtrace(std::vector<int>& nums, std::vector<bool>& judge)
        {
            if (temp.size() == nums.size())
            {
                ret.push_back(temp);
                return;
            }

            for (int i = 0; i < nums.size(); i++)
            {
                if (judge[i])
                    continue;

                judge[i] = true;
                temp.push_back(nums[i]);

                backtrace(nums, judge);
                
                temp.pop_back();
                judge[i] = false;
            }
        }

        std::vector<std::vector<int>> permute(std::vector<int>& nums) 
        {
            std::vector<bool> judge(nums.size(), false);

            backtrace(nums, judge);
            
            return ret;
        }
};