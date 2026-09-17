#include <string>
#include <vector>

//动态规划，定义 dp[i] 为前 i 个在字符解码个数
// 一个一个判断，先判断这一个是否为0，非0则与前一个构成类别相同
//然后再判断前一个是否为0，如果非0,则判断和是否大于26,如不大于，则加上前n - 2个字符的解码个数
//时间复杂度：O(n)
class Solution 
{
    public:
        int numDecodings(std::string s) 
        {
            if (*s.begin() == '0')
                return 0;

            if (s.size() == 1)
                return 1;

            std::vector<int> dp(s.size() + 1);

            dp[0] = 1;
            dp[1] = 1;

            for (int n = 2; n <= s.size(); n++)
            {
                if (s[n - 1] != '0')
                {
                    dp[n] = dp[n - 1];

                    int n1 = s[n - 1] - '0';
                    int n2 = (s[n - 2] - '0') * 10;

                    if (n2 == 0)
                        continue;

                    int sum = n1 + n2;

                    if (sum <= 26)
                    {
                        dp[n] += dp[n - 2];
                    }
                }
                else 
                {
                    if (s[n - 2] == '1' || s[n - 2] == '2')
                        dp[n] = dp[n - 2];
                }
            }

            return dp.back();
        }
};