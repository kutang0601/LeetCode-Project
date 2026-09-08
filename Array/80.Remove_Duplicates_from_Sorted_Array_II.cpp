#include <vector>

//时间复杂度：O(n)
class Solution 
{
    public:
        int removeDuplicates(std::vector<int>& nums) 
        {
            if (nums.size() <= 2)
                return nums.size();

            int slow = 0;

            int lenth = 0;
            int count = 0;
            
            for (int n = 0; n < nums.size(); n++)
            {
                if (slow == 0)
                {
                    slow++;
                    count++;
                    continue;
                }

                //如果更换数字则，添加并且更新数据
                if (nums[n] != nums[slow - 1])
                {
                    lenth += count;
                    count = 0;

                    nums[slow] = nums[n];
                    slow++;
                    count++;
                }
                else 
                {
                    //如果不够两个则增加在后面
                    if (count != 2)
                    {
                        nums[slow] = nums[n];
                        slow++;
                        count++;
                    }
                }
            }

            lenth += count;

            return lenth;
        }
};

//思路优化
class Solution1
{
    public:
        int removeDuplicates(std::vector<int>& nums) 
        {
            int slow = 0;

            for (int fast = 0; fast < nums.size(); fast++)
            {
                //如果不够两个或者当前元素和排好的倒数第二个不同才能添加
                if (slow < 2 || nums[fast] != nums[slow - 2])
                {
                    nums[slow] = nums[fast];
                    slow++;
                }
            }

            return slow;
        }
};