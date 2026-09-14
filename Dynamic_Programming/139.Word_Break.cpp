#include <vector>
#include <string>

//动态规划
//定义dp代表第n个位置能否到达
//时间复杂度：O()
class Solution 
{
    public:
        bool wordBreak(std::string s, std::vector<std::string>& wordDict) 
        {
            std::vector<bool> dp(s.size() + 1, false);

            dp[0] = true;

            //从第一个字符开始判断
            for (int n = 1; n < s.size() + 1; n++)
            {
                //每次都分割看是否能够构成新的单词
                for (int m = 0; m < n; m++)
                {
                    //如果已经构成了单词则跳过
                    if (!dp[m])
                        continue;

                    std::string temp;
                    temp.append(s, m, n - m);

                    //循环遍历，在字典中寻找
                    for (auto it : wordDict)
                    {
                        if (temp == it)
                        {
                            dp[n] = true;
                            break;
                        }
                    }

                    if (dp[n])
                        break;
                }
            }

            return dp.back();
        }
};