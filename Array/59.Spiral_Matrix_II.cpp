#include <vector>

//按照逆时针顺序一圈一圈遍历每个位置，然后填入对应值
//时间复杂度：O(n)
class Solution 
{
    public:
        std::vector<std::vector<int>> generateMatrix(int n)
        {  
            std::vector<std::vector<int>> ret(n, std::vector<int>(n)); 

            int first = 0;
            int second = 0;

            int reduce = 1;
            int num = 1;

            while (num <= n * n)
            {
                int row = first;
                int list = second + 1;

                ret[first][second] = num;
                num++;

                if (first == n - reduce)
                {
                    while (list <= n - reduce)
                    {
                        ret[row][list] = num;
                        list++;
                        num++;
                    }

                    break;
                }

                if (second == n - reduce)
                {
                    row++;

                    while (row <= n - reduce)
                    {
                        ret[row][list] = num;
                        row++;
                        num++;
                    }

                    break;
                }

                while (row == first && list < n - reduce)
                {
                    ret[row][list] = num;
                    list++;
                    num++;
                }

                if (row != n - reduce)
                {
                    while (row < n - reduce&& list == n - reduce)
                    {
                        ret[row][list] = num;
                        row++;
                        num++;
                    }
                }
                
                if (list != second)
                {
                    while (row == n - reduce && list > second) 
                    {
                        ret[row][list] = num;
                        list--;
                        num++;
                    }
                }

                if (row != first)
                {
                    while (row > first && list == second) 
                    {
                        ret[row][list] = num;
                        row--;
                        num++;
                    }
                }

                first++;
                second++;
                reduce++;
            }

            return ret;
        }
};
