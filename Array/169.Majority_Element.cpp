#include <algorithm>
#include <map>
#include <vector>

// 排序后，如果是超过一半的元素，那么中间值必定是
// 时间复杂度：O(n * log(n))
class Solution {
public:
    int majorityElement(std::vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());
        
        return nums[nums.size() / 2];
    }
};

//使用图来解决，先存储，然后遍历寻找最大的值
//时间复杂度：O(n)
class Solution1 {
public:
    int majorityElement(std::vector<int>& nums) 
    {
        std::map<int, int> statistic;

        for (auto it : nums)
        {
            auto n = statistic.find(it);
            if (n != statistic.end())
            {
                n->second++;
            }
            else 
            {
                statistic[it] = 1;
            }
        }

        auto it = std::max_element(statistic.begin(), statistic.end(), [](const auto& a, const auto& b) 
        {
                return a.second < b.second;
        });

        return it->first;
    }
};
