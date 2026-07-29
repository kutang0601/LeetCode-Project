#include <stdlib.h>

//逻辑正确， 时间与空间复杂度太高，超出限制时间与空间
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    if (numsSize < 3)
    {   
        return NULL;
    }

    int judge = 0;
    for (int p = 0; p < numsSize; p++)
    {
        if (nums[p] != 0)
            judge++;
    }

    

    int arr_positive[10000] = {0};
    int arr_negative[10000] = {0};
    int max_positive = 0;
    int max_negative = 0;

    for (int a = 0; a < numsSize; a++)
    {
        if (nums[a] >= 0)
        {
            arr_positive[nums[a]]++;
            if (nums[a] > max_positive)
                max_positive = nums[a];
        }
        else
        {
            arr_negative[-nums[a]]++;
            if (-nums[a] > max_negative)
                max_negative = -nums[a];
        }
    }

    int** ret = (int**)malloc(sizeof(int*) * 10000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 10000);
    for (int n = 0; n < 10000; n++)
    {
        ret[n] = (int*)malloc(sizeof(int) * 3);
    }

    for (int m = 0; m < 10000; m++)
    {
        (*returnColumnSizes)[m] = 3;
    }

    int x = 0;
    arr_negative[0] = 1;
    for (int b = 0; b <= max_positive ; b++)
    {
        for (int c = b; c <= max_positive; c++)
        {
            if (arr_positive[b] != 0 && arr_positive[c] != 0)
            {
                if (b == c)
                {
                    if ((arr_positive[b] < 2 && b != 0) || (arr_positive[b] < 3 && b == 0))
                        continue;
                }
                int tmp = b + c;
                if (arr_negative[tmp] != 0)
                {
                    ret[x][0] = b;
                    ret[x][1] = c;
                    ret[x][2] = -tmp;
                    x++;
                }
            }
        }
    }

    for (int d = 1; d <= max_negative; d++)
    {
        for (int e = d; e <= max_negative; e++)
        {
            if (arr_negative[d] != 0 && arr_negative[e] != 0)
            {
                if (d == e)
                {
                    if (arr_negative[d] < 2)
                        continue;
                }
                int tmp = d + e;
                if (arr_positive[tmp] != 0)
                {
                    ret[x][0] = -d;
                    ret[x][1] = -e;
                    ret[x][2] = tmp;
                    x++;
                }
            }
        }
    }

    *returnSize = x;

    return ret;
}

//代码优化
#include <stdlib.h>

int** New_threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    if (numsSize < 3) 
    {
        *returnSize = 0;
        return NULL;
    }

    int arr_positive[100001] = {0};
    int arr_negative[100001] = {0};
    int max_positive = 0;
    int max_negative = 0;
    int zero_cnt = 0;

    for (int i = 0; i < numsSize; i++) 
    {
        if (nums[i] > 0) {
            arr_positive[nums[i]]++;
            if (nums[i] > max_positive) max_positive = nums[i];
        } else if (nums[i] < 0) {
            int val = -nums[i];
            arr_negative[val]++;
            if (val > max_negative) max_negative = val;
        } else {
            zero_cnt++;
        }
    }

    int pos_vals[100001];
    int neg_vals[100001];
    int pos_size = 0, neg_size = 0;
    for (int i = 1; i <= max_positive; i++) 
    {
        if (arr_positive[i] > 0) pos_vals[pos_size++] = i;
    }
    for (int i = 1; i <= max_negative; i++) 
    {
        if (arr_negative[i] > 0) neg_vals[neg_size++] = i;
    }

    int total = 0;
    if (zero_cnt >= 3) 
        total++;
    if (zero_cnt >= 1) 
    {
        for (int i = 0; i < pos_size; i++) 
        {
            int a = pos_vals[i];
            if (arr_negative[a] > 0) 
                total++;
        }
    }

    for (int i = 0; i < pos_size; i++) 
    {
        int b = pos_vals[i];
        for (int j = i; j < pos_size; j++) 
        {
            int c = pos_vals[j];
            if (b == c && arr_positive[b] < 2) 
                continue;
            int sum = b + c;
            if (sum <= max_negative && arr_negative[sum] > 0) 
                total++;
        }
    }

    for (int i = 0; i < neg_size; i++) {
        int d = neg_vals[i];
        for (int j = i; j < neg_size; j++) {
            int e = neg_vals[j];
            if (d == e && arr_negative[d] < 2) 
                continue;
            int sum = d + e;
            if (sum <= max_positive && arr_positive[sum] > 0) 
                total++;
        }
    }

    int** ret = (int**)malloc(total * sizeof(int*));
    *returnColumnSizes = (int*)malloc(total * sizeof(int));
    for (int i = 0; i < total; i++) 
    {
        ret[i] = (int*)malloc(3 * sizeof(int));
        (*returnColumnSizes)[i] = 3;
    }

    int idx = 0;
    if (zero_cnt >= 3) 
    {
        ret[idx][0] = 0; ret[idx][1] = 0; ret[idx][2] = 0;
        idx++;
    }
    if (zero_cnt >= 1) 
    {
        for (int i = 0; i < pos_size; i++) 
        {
            int a = pos_vals[i];
            if (arr_negative[a] > 0) 
            {
                ret[idx][0] = -a; 
                ret[idx][1] = 0; 
                ret[idx][2] = a;
                idx++;
            }
        }
    }

    for (int i = 0; i < pos_size; i++) 
    {
        int b = pos_vals[i];
        for (int j = i; j < pos_size; j++) 
        {
            int c = pos_vals[j];
            if (b == c && arr_positive[b] < 2) 
                continue;
            int sum = b + c;
            if (sum <= max_negative && arr_negative[sum] > 0) 
            {
                ret[idx][0] = b;
                ret[idx][1] = c;
                ret[idx][2] = -sum;
                idx++;
            }
        }
    }

    for (int i = 0; i < neg_size; i++) 
    {
        int d = neg_vals[i];
        for (int j = i; j < neg_size; j++) 
        {
            int e = neg_vals[j];
            if (d == e && arr_negative[d] < 2) 
                continue;
            int sum = d + e;
            if (sum <= max_positive && arr_positive[sum] > 0) 
            {
                ret[idx][0] = -d;
                ret[idx][1] = -e; 
                ret[idx][2] = sum;
                idx++;
            }
        }
    }

    *returnSize = total;

    return ret;
}