#include <string>
#include <vector>

//回溯，分成四段，每段只选择1-3个，选择后判断是否符合条件
//时间复杂度：O(1)
class Solution 
{
    public:
        std::vector<std::string> ret;

        void backtrace(const std::string& s, std::string& temp,int start, int count)
        {
            if (count == 4)
            {
                if (s.size() == start)
                    ret.push_back(temp);

                return;
            }

            int num = 0;
            int beforesize = temp.size();

            for (int n = start; n < s.size() && n < start + 3; n++)
            {
                if (n > start && s[start] == '0')
                    break;

                num = num * 10 + s[n] - '0';

                if (num > 255)
                    break;

                if (count != 0)
                    temp += '.';

                temp.append(s, start, n - start + 1);

                backtrace(s, temp, n + 1, count + 1);

                temp.resize(beforesize);
            }
        }

        std::vector<std::string> restoreIpAddresses(std::string s) 
        {
            std::string temp;

            backtrace(s, temp, 0, 0);

            return ret;
        }
};