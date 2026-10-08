#include <algorithm>
#include <vector>
class Solution 
{
    public:
        bool isPerfectSquare(long long n) 
        {
            long long left = 0;
            long long right = n;

            while (left <= right)
            {
                int mid = (left + right) / 2;

                if (mid == 0)
                {
                    if (n == 0)
                        return true;

                    left = 1;
                    continue;
                }

                if (mid <= n / mid)
                {
                    if (mid * mid == n)
                        return true;

                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }

            return false;
        }

        int numSquares(int n) 
        {
            std::vector<int> dp(n + 1, n + 1);

            std::vector<int> count;

            dp[0] = 0;

            for (int i = 1; i <= n; i++)
            {
                if (isPerfectSquare(i))
                {
                    dp[i] = 1;

                    count.push_back(i);

                    continue;
                }

                for (int j = 0; j < count.size(); j++)
                {
                    dp[i] = std::min(dp[i], dp[i - count[j]] + 1);
                }
            }

            return dp[n];
        }
};
