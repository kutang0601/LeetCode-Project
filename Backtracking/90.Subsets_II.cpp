#include <algorithm>
#include <vector>

class Solution 
{
    public:
        std::vector<std::vector<int>> ret;
        std::vector<int> part;

        void backtrace(std::vector<int>& nums, int start)
        {
            ret.push_back(part);

            for (int n = start; n < nums.size(); n++)
            {
                part.push_back(nums[n]);

                backtrace(nums, n + 1);

                while (n < nums.size() - 1 && nums[n] == nums[n + 1])
                {
                    n++;
                }

                part.pop_back();
            }
        }

        std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
            std::sort(nums.begin(), nums.end());

            backtrace(nums, 0);

            return ret;
        }
};