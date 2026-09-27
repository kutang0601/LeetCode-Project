#include <string>

//从前往后走，分割出来一个单词就头插
//时间复杂度：O(n ^ 2)
class Solution 
{
    public:
        std::string reverseWords(std::string s) 
        {
            std::string ret;
            std::string temp;
            
            int n = 0;

            while (n < s.size() && s[n] == ' ')
            {
                n++;
            }
            
            while (n < s.size())
            {
                if (s[n] == ' ' && !temp.empty())
                {
                    if (!ret.empty())
                    {
                        temp.push_back(' ');
                    }


                    ret.insert(0, temp);

                    temp.clear();

                    while (n < s.size() && s[n] == ' ')
                    {
                        n++;
                    }
                }
                else 
                {
                    temp.push_back(s[n]);
                    n++;
                }
            }

            if (!temp.empty())
            {
                if (!ret.empty())
                {
                    temp.push_back(' ');
                }

                ret.insert(0, temp);
            }

            return ret;
        }
};