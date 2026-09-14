#include <algorithm>
#include <vector>

//用dp表示现在这个位置能到达的最大的高度
//然后去判别与前面是否能够组成，并且不断降低
//时间复杂度：O(m * n * min(m, n))
class Solution 
{
    public:
        int maximalSquare(std::vector<std::vector<char>>& matrix) 
        {
            if (!matrix.size())
                return 0;

            int max_area = 0;

            std::vector<std::vector<int>> dp(matrix.size(), std::vector<int>(matrix[0].size(), 0));
            
            for (int i = 0; i < matrix[0].size(); i++)
            {
                if (matrix[0][i] == '1')
                {
                    dp[0][i] = 1;
                    max_area = 1;
                }
            }

            for (int n = 1; n < matrix.size(); n++)
            {
                for (int m = 0; m < matrix[n].size(); m++)
                {
                    if (matrix[n][m] == '1')
                    {
                        dp[n][m] = dp[n - 1][m] + 1;
                        max_area = std::max(max_area, 1);

                        int count = 0;

                        for (int p = dp[n][m]; p > 0; p--)
                        {
                            int count = 0;

                            for (int i = 0; i < p; i++)
                            {
                                if (m - i >= 0 && dp[n][m - i] >= p)
                                    count++;
                            }

                            if (count == p)
                            {
                                max_area = std::max(p * p, max_area);
                                break;
                            }
                        }
                    }
                }
            }
            
            return max_area;
        }
};

//思路优化
//定义dp[i][j]为以i，j位置为右下角最大的边长，结果为分别判别此位置的左，上，左上的最小 + 1
//时间复杂度：O(n * m)
class Solution1
{
    public:
        int maximalSquare(std::vector<std::vector<char>>& matrix)
        {
            if (matrix.empty() || matrix[0].empty())
                return 0;
            
            std::vector<std::vector<int>> dp( matrix.size() + 1, std::vector<int>( matrix[0].size() + 1, 0));

            int maxSide = 0;

            for (int i = 1; i <= matrix.size(); i++)
            {
                for (int j = 1; j <= matrix[0].size(); j++)
                {
                    if (matrix[i - 1][j - 1] == '1')
                    {
                        dp[i][j] = std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;

                        maxSide = std::max(maxSide, dp[i][j]);
                    }
                }
            }

            return maxSide * maxSide;
        }
};