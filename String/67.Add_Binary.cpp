#include <algorithm>
#include <string>

//从后往前遍历，不断相加并且存储进位，最后反转
//时间复杂度：O(Max(a.size(), b.size()))
class Solution
{
    public:
        std::string addBinary(std::string a, std::string b)
        {
            std::string ret;

            int store = 0;

            int i = a.size() - 1;
            int j = b.size() - 1;

            while (i >= 0 || j >= 0)
            {
                int sum = store;

                if (i >= 0)
                {
                    sum += a[i] - '0';
                    i--;
                }

                if (j >= 0)
                {
                    sum += b[j] - '0';
                    j--;
                }

                if (sum >= 2)
                    store = 1;
                else
                    store = 0;

                ret.push_back(sum % 2 + '0');
            }

            if (store == 1)
                ret.push_back('1');

            std::reverse(ret.begin(), ret.end());

            return ret;
        }
};