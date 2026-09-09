#include <string>
#include <vector>

//回溯解决
//时间复杂度：O(n * 2 ^ n)
class Solution 
{
    public:
        std::vector<std::vector<std::string>> ret;
        std::vector<std::string> temp;

        //判断是否是回文
        bool IsPalindrome(const std::string& s)
        {
            if (s.size() == 1)
                return true;

            int left = 0;
            int right = s.size() - 1;

            while (right >= left)
            {
                if (s[right] != s[left])
                    return false;

                right--;
                left++;
            }

            return true;
        }

        //枚举所有的情况，如果当前分割部分的字符串不构成回文，则尝试下一种可能
        void BackTrace(const std::string& s, int now) 
        {
            if (now == s.size())
            {
                ret.push_back(temp);
                return;
            }

            for (auto it = now; it < s.size(); it++)
            {
                std::string mid;
                mid.append(s, now, it - now + 1);
                
                if (IsPalindrome(mid))
                {
                    temp.push_back(mid);

                    BackTrace(s, it + 1);

                    temp.pop_back();
                }
            }
        }

        std::vector<std::vector<std::string>> partition(std::string s) 
        {
            BackTrace(s, 0);

            return ret;
        }
};