#include <stdlib.h>

struct ListNode 
{
    int val;
    struct ListNode *next;
};

//时间复杂度O(n)
//先将前面重复除去，然后将后面重复除去
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head || !head->next)
        return head;

    while (head->next && head->val == head->next->val)
    {
        head = head->next;
        if (!head->next)
        {
            head = NULL;
            break;
        }
        if (head->next && head->val != head->next->val)
            head = head ->next;
    }

    if (!head || !head->next)
        return head;

    struct ListNode* pcur = head;
    struct ListNode* prev = NULL;

    while (pcur && pcur->next)
    {
        prev = pcur;
        pcur = pcur->next;

        while (pcur->next && pcur->val == pcur->next->val)
        { 
            pcur = pcur->next;
            if (!pcur->next)
            {
                pcur = NULL;
                break;
            }
            if (pcur->next && pcur->val != pcur->next->val)
            {
                pcur = pcur->next;
            }
        }
        prev->next = pcur;
    }

    return head;
}