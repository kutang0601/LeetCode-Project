#include <string>
#include <vector>

//时间复杂度：O(n)
class Solution 
{
    public:
        int firstUniqChar(std::string s) 
        {
            //judge用来记录是否出现或重复出现过，squence用来记录每个字母出现的顺序
            std::vector<bool> judge(26, false);
            std::vector<int> squence(26, 0);

            int count = 1;

            for (int n = 0; n < s.size(); n++)
            {
                //出现过一次且在出现则记录为重复出现
                if (!judge[s[n] - 'a'] && squence[s[n] - 'a'] != 0)
                {
                    judge[s[n] - 'a'] = true;
                }

                //第一次出现则记录其出现的顺序
                if (!judge[s[n] - 'a'])
                {
                    squence[s[n] - 'a'] = count;
                 
                    count++;
                }
            }

            //ret用来记录返回下标，p记录不重复且最早出现的，no记录不重复且最早出现的字符
            int ret = -1;
            int p = 0;
            char no = '\0';

            for (int m = 0; m < 26; m++)
            {
                if (!judge[m] && squence[m] != 0)
                {
                    if (p == 0 || squence[m] < p)
                    {
                        p = squence[m];
                        no = m + 'a';
                    }
                }
            }

            //遍历容器，寻找下标
            for (int o = 0; o < s.size(); o++)
            {
                if (s[o] == no)
                {
                    ret = o;
                    break;
                }
            }

            return ret;
        }
};

//逻辑优化
//时间复杂度：O(n)
class Solution1
{
    public:
        int firstUniqChar(std::string s)
        {
            int count[26] = {0};

            for (int i = 0; i < s.size(); i++)
            {
                count[s[i] - 'a']++;
            }

            for (int i = 0; i < s.size(); i++)
            {
                if (count[s[i] - 'a'] == 1)
                {
                    return i;
                }
            }

            return -1;
        }
};