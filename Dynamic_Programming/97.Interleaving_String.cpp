#include <string>
#include <vector>

//回溯解决
//超出时间限制，时间复杂度：O(n ^ m)
class Solution 
{
    public:
        bool ret;
        void backtrace(std::string& judge, const std::string& s1, const std::string& s2, const std::string& s3, int n, int m)
        {
            if (judge == s3)
                ret = true;

            if (n < s1.size())
            {
                judge.push_back(s1[n]);
                backtrace(judge, s1, s2, s3, n + 1, m);
                judge.pop_back();
            }

            if (m < s2.size())
            {
                judge.push_back(s2[m]);
                backtrace(judge, s1, s2, s3, n, m + 1);
                judge.pop_back();
            }
        }

        bool isInterleave(std::string s1, std::string s2, std::string s3) 
        {
            if (s1.size() + s2.size() != s3.size())
                return false;

            if (s1.size() == 1 && s2.size() == 0 && s1[0] != s3[0])
                return false;

            if (s2.size() == 1 && s1.size() == 0 && s2[0] != s3[0])
                return false;

            std::string judge;

            backtrace(judge, s1, s2, s3, 0, 0);

            return ret;
        }
};

//思路优化
//时间复杂度：O(n * m)
class Solution1
{
    public:
        bool isInterleave(std::string s1, std::string s2, std::string s3) 
        {
            if (s1.size() + s2.size() != s3.size())
                return false;

            std::vector<std::vector<bool>> dp(s1.size() + 1, std::vector<bool>(s2.size() + 1, false));

            dp[0][0] = true;

            for (int n = 0; n <= s1.size(); n++)
            {
                for (int m = 0; m <= s2.size(); m++)
                {
                    if (n == 0 && m == 0)
                        continue;
                    
                    //如果s1现在是前n(> 0)个，判断其前n-1是否能够到实现，如果可以实现并且，s1现在这个字母与s3的相同，则为true
                    if (n > 0 && dp[n - 1][m] && s1[n - 1] == s3[n + m - 1])
                        dp[n][m] = true;

                    //如果s2现在是前m(> 0)个，判断其前m-1是否能够到实现，如果可以实现并且，s2现在这个字母与s3的相同，则为true
                    if (m > 0 && dp[n][m - 1] && s2[m - 1] == s3[n + m - 1])
                        dp[n][m] = true;
                }
            }

            return dp.back().back();
        }
};