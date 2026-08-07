#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* rotateRight(struct ListNode* head, int k) 
{
    if (!head || !(head->next) || k == 0) 
        return head;

    int lenth = 0;
    struct ListNode* plist = head;

    while(plist)
    {
        plist = plist->next;
        lenth++;
    }

    k %= lenth;

    if (!k)
    {
        return head;
    }

    int n = lenth - k;
    struct ListNode* pcur = head;
    struct ListNode* front = NULL;

    while(n--)
    {
        front = pcur;
        pcur = pcur->next;
    }

    struct ListNode* newhead = pcur;
    front->next = NULL;

    while (pcur->next)
    {
        pcur = pcur->next;
    }

    pcur->next = head;

    return newhead;
}