#include <algorithm>
#include <vector>

//排序后，先确定双层循环遍历，确定两个值的和，在使用双指针，在剩下的寻找
//时间复杂度：O(n ^ 2 * k + n ^ 3)
class Solution
{
    public:
        std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target)
        {
            std::vector<std::vector<int>> ret;

            std::sort(nums.begin(), nums.end());

            for (int i = 0; i < nums.size() - 1; i++)
            {
                for (int m = i + 1; m < nums.size(); m++)
                {
                    std::vector<int> temp;

                    temp.push_back(nums[i]);
                    temp.push_back(nums[m]);

                    long long sum = (long long)target - nums[i] - nums[m];

                    int left = m + 1;
                    int right = nums.size() - 1;

                    while (right > left)
                    {
                        if (nums[left] + nums[right] == sum)
                        {
                            temp.push_back(nums[left]);
                            temp.push_back(nums[right]);

                            auto it = std::find(ret.begin(), ret.end(), temp);

                            if (it == ret.end())
                            {
                                ret.push_back(temp);
                            }

                            temp.pop_back();
                            temp.pop_back();

                            left++;
                            right--;
                        }
                        else if (nums[left] + nums[right] > sum)
                        {
                            right--;
                        }
                        else
                        {
                            left++;
                        }
                    }
                }
            }

            return ret;
        }
};