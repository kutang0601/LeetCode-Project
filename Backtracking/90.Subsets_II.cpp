#include <algorithm>
#include <vector>

class Solution
{
    public:
        std::vector<std::vector<int>> ret;
        std::vector<int> path;

        void backtracking(std::vector<int>& nums, int start)
        {
            ret.push_back(path);

            for (int i = start; i < nums.size(); i++)
            {
                // 同一层去重
                if (i > start && nums[i] == nums[i - 1])
                    continue;

                path.push_back(nums[i]);

                backtracking(nums, i + 1);

                path.pop_back();
            }
        }

        std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums)
        {
            std::sort(nums.begin(), nums.end());

            backtracking(nums, 0);

            return ret;
        }
};