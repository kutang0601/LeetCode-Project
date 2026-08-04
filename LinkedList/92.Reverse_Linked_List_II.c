#include <stdlib.h>

struct ListNode 
{
    int val;
    struct ListNode *next;
};

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) 
{
    int mid = right - left;

    if (!head || !(head->next) || left == right)
        return head;

    struct ListNode* pcur = head;
    struct ListNode* pnext = head->next;
    struct ListNode* plist = NULL;

    struct ListNode* pfront1 = NULL;
    struct ListNode* pnext1 = NULL;

    int judge = left;

    while (--left)
    {
        plist = pcur;
        pcur = pcur->next;
        pnext = pcur->next;
    }
    
    pfront1 = plist;
    pnext1 = pcur;

    while (mid--)
    {
        struct ListNode* tmp = pnext->next;
        pnext->next = pcur;
        pcur = pnext;
        pnext = tmp; 
    }

    if (judge == 1)
    {
        pnext1->next = pnext;
        head = pcur;
    }
    else
    {
        pfront1->next = pcur;
        pnext1->next = pnext;
    }

    return head;
}