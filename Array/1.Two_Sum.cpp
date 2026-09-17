#include <unordered_map>
#include <vector>

//暴力枚举
//时间复杂度：O(n ^ 2)
class Solution 
{
    public:
        std::vector<int> twoSum(std::vector<int>& nums, int target) 
        {
            for (int i = 0; i < nums.size(); i++)
            {
                for (int j = i + 1; j < nums.size(); j++)
                {
                    if (nums[i] + nums[j] == target)
                    {
                        return {i, j};
                    }
                }
            }

            return {};
        }
};

//思路优化
//哈希表，每次寻找是否存在目标数与这个数的差值，存在则返回，不存在则储存
//时间复杂度：O(n)
class Solution1
{
    public:
        std::vector<int> twoSum(std::vector<int>& nums, int target)
        {
            std::unordered_map<int, int> stock;

            for (int n = 0; n < nums.size(); n++)
            {
                int minus = target - nums[n];

                auto it = stock.find(minus);

                if (it != stock.end())
                {
                    return {n, it->second};
                }

                stock[nums[n]] = n;
            }

            return {};
        }
};