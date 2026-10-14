//每位累加，然后存储，判断，>=10则继续循环  
//时间复杂度：O(log(n))
class Solution 
{
    public:
        int addDigits(int num) 
        {
            int ret = num;
            while (ret >= 10)
            {
                int count = 0;
                int temp = ret;

                while (temp > 0)
                {
                    count += temp % 10;
                    temp /= 10;
                }

                ret = count;
            }    

            return ret;
        }
};