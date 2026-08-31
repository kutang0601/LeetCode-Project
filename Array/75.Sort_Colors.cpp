#include <vector>

//将其分为三部分，定义一个left、与right,分别用来表示0和2的存储位置，定义i为当前位置
//时间复杂度：O(n)
class Solution 
{
    public:
        void sortColors(std::vector<int>& nums) 
        {
            if (nums.size() == 1 || nums.empty())
                return;

            int left = 0;
            int right = nums.size() - 1;
            int i  = 0;

            while (i <= right)
            {
                if (nums[i] == 0)
                {
                    int temp = nums[left];
                    nums[left] = 0;
                    nums[i] = temp;
                    left++;
                    i++;
                }
                else if (nums[i] == 2)
                {
                    int temp = nums[right];
                    nums[right] = 2;
                    nums[i] = temp;
                    right--;
                }
                else   
                {
                    i++;
                }
            }
        }
};