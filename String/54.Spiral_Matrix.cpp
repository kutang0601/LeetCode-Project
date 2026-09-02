#include <vector>

//一圈一圈向内处理，最后如果只剩一行或者一列，只处理这一行或者这一列
//时间复杂度：O(n)
class Solution 
{
    public:
        std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) 
        {  
            std::vector<int> ret;

            if (matrix.empty())
                return ret;

            int first = 0;
            int second = 0;

            int judge1 = matrix.size();
            int judge2 = matrix[0].size();
            int reduce = 1;

            while (first < judge1 - reduce + 1 && second < judge2 - reduce + 1)
            {
                int row = first;
                int list = second + 1;

                ret.push_back(matrix[first][second]);

                if (first == matrix.size() - reduce)
                {
                    while (list <= matrix[row].size() - reduce)
                    {
                        ret.push_back(matrix[row][list]);
                        list++;
                    }

                    break;
                }

                if (second == matrix[0].size() - reduce)
                {
                    row++;

                    while (row <= matrix.size() - reduce)
                    {
                        ret.push_back(matrix[row][second]);
                        row++;
                    }

                    break;
                }


                while (row == first && list < matrix[row].size() - reduce)
                {
                    ret.push_back(matrix[row][list]);
                    list++;
                }

                if (row != matrix.size() - reduce)
                {
                    while (row < matrix.size() - reduce&& list == matrix[row].size() - reduce)
                    {
                        ret.push_back(matrix[row][list]);
                        row++;
                    }
                }
                
                if (list != second)
                {
                    while (row == matrix.size() - reduce && list > second) 
                    {
                        ret.push_back(matrix[row][list]);
                        list--;
                    }
                }

                if (row != first)
                {
                    while (row > first && list == second) 
                    {
                        ret.push_back(matrix[row][list]);
                        row--;
                    }
                }
                
                first++;
                second++;
                reduce++;
            }

            return ret;
        }
};