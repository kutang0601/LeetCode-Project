//递归，不断向下，如果比4大，判断是否能整除4，如果小，判断是否等于4或者1
//时间复杂度：O(log(n))
class Solution 
{
public:
    bool ret = false;

    void recurison(int n)
    {
        if (n > 4 && n % 4 == 0)
        {
            recurison(n / 4);
        }
        else 
        {
            if (n == 4)
                ret = true;

            return;
        }
    }

    bool isPowerOfFour(int n) 
    {
        if (n == 1)
            return true;

        recurison(n);

        return ret;
    }
};

//思路优化
//位运算，时间复杂度：O(1)
class Solution1
{
public:
    bool isPowerOfFour(int n)
    {
        return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555) != 0;
    }
};