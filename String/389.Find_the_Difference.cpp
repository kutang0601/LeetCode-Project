#include <string>
#include <unordered_map>

//使用哈希图，一个存字符，一个存出现次数，遍历两次，一次统计，一次删除就可以
//时间复杂度：O(n^2)
class Solution 
{
    public:
        char findTheDifference(std::string s, std::string t) 
        {
            std::unordered_map<char, int> judge;

            for (auto& it : s)
            {
                auto ch = judge.find(it);
                
                if (ch != judge.end())
                {
                    judge[it]++;
                }
                else
                {
                    judge[it] = 1;
                }
            }

            for (auto& it : t)
            {
                auto ch = judge.find(it);
                
                if (ch != judge.end())
                {
                    judge[it]--;
                }
                else
                {
                    judge[it] = -1;
                }
            }

            for (const auto& [k, v]: judge)
            {
                if (v == -1)
                    return k;
            }

            return 0;
        }
};