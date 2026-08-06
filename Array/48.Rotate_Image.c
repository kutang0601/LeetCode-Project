//一层一层往内部遍历，先处理一个四个边，然后处理下一个，直到这一层处理完，处理下一层
void rotate(int** matrix, int matrixSize, int* matrixColSize) 
{
    int a = 0;
    int b = 0;

    while (a < matrixSize / 2)
    {
        int o1 = a;
        int o2 = b;

        int len = matrixSize - 1 - a - b;
        int len1 = matrixSize - 1 - a;
        int len2 = matrixSize - 1 - b;

        while (b < len2)
        {
            int a2 = a;
            int b2 = b;

            int r = len2 - b;

            b = len2;
            a = o1 + len - r;

            int tmp = matrix[a][b];

            matrix[a][b] = matrix[a2][b2];

            while(a != a2 || b != b2)
            {
                // 上边 -> 右边
                if (b == len2 && a < len1)
                {
                    int p = len1 - a;

                    a = len1;
                    b = len2 - (len - p);
                }

                // 右边 -> 下边
                else if(a == len1 && b > o2)
                {
                    int p = b - o2;

                    b = o2;
                    a = len1 - (len - p);
                }

                // 下边 -> 左边
                else if(b == o2 && a > o1)
                {
                    int p = a - o1;

                    a = o1;
                    b = o2 + len - p;
                }


                int tmp1 = matrix[a][b];

                matrix[a][b] = tmp;

                tmp = tmp1;
            }

            a = a2;
            b = b2 + 1;
        }

        a = o1 + 1;
        b = o2 + 1;
    }
}
