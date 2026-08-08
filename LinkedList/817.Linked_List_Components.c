#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}


int find(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;

    while(left <= right)
    {
        int mid = left + (right - left) / 2;

        if(nums[mid] == target)
        {
            return 1;
        }
        else if(nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return 0;
}


int numComponents(struct ListNode* head, int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), compare);


    int count = 0;

    struct ListNode* cur = head;


    while(cur)
    {
        // 当前节点属于nums
        if(find(nums, numsSize, cur->val))
        {
            // 连续组件开始
            count++;

            // 跳过后面连续属于nums的节点
            while(cur && find(nums, numsSize, cur->val))
            {
                cur = cur->next;
            }
        }
        else
        {
            cur = cur->next;
        }
    }


    return count;
}