
#include <algorithm>
#include <string>

class Solution 
{
    public:
        std::string addStrings(std::string num1, std::string num2) 
        {
            std::string ret;

            int i = num1.size() - 1;
            int j = num2.size() - 1;
            int carry = 0;

            while (i >= 0 || j >= 0 || carry > 0)
            {
                int a = 0;
                int b = 0;

                if (i >= 0)
                {
                    a = num1[i] - '0';
                    i--;
                }

                if (j >= 0)
                {
                    b = num2[j] - '0';
                    j--;
                }

                int sum = a + b + carry;

                ret.push_back(sum % 10 + '0');
                carry = sum / 10;
            }

            std::reverse(ret.begin(), ret.end());

            return ret;
        }
};
