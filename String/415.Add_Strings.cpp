
#include <algorithm>
#include <string>

class Solution 
{
    public:
        std::string addStrings(std::string num1, std::string num2) 
        {
            std::string ret;

            int n1 = num1.size() - 1;
            int n2 = num2.size() - 1;

            int count = 0;

            while (n1 >= 0 && n2 >= 0)
            {
                int sum = (num1[n1] - '0') + (num2[n2] - '0') + count;

                count = sum / 10;

                ret.push_back((sum % 10) + '0');

                n1--;
                n2--;
            }

            while (n1 >= 0)
            {
                int sum = (num1[n1] - '0') + count;

                count = sum / 10;

                ret.push_back((sum % 10) + '0');

                n1--;
            }

            while (n2 >= 0)
            {
                int sum = (num2[n2] - '0') + count;

                count = sum / 10;

                ret.push_back((sum % 10) + '0');

                n2--;
            }

            if (count > 0)
                ret.push_back(count + '0');

            std::reverse(ret.begin(), ret.end());

            return ret;
        }
};
