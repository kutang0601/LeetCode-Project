#include <stdlib.h>

struct ListNode 
{
     int val;
     struct ListNode *next;
};

struct ListNode* partition(struct ListNode* head, int x) {
    if (!head || !head->next)
        return head;

    struct ListNode* head1 = NULL;
    struct ListNode* head2 = NULL;

    struct ListNode* ret1 = NULL;
    struct ListNode* ret2 = NULL;

    struct ListNode* pcur = head;
    while (pcur)
    {
        if (pcur->val < x)
        {
            if (!head1)
            {
                head1 = pcur;
                ret1 = head1;
            }
            else
            {
                head1->next = pcur;
                head1 = pcur;
            }
        }
        else
        {
            if (!head2)
            {
                head2 = pcur;
                ret2 = head2;
            }
            else
            {
                head2->next = pcur;
                head2 = pcur;
            }
        }

        pcur = pcur->next;
    }

    if (head1 && head2)
    {
        head1->next = ret2;
        head2->next = NULL;

        return ret1;
    }
    else if (head1)
    {
        head1->next = NULL;
        return ret1;
    }
    else
    {
        head2->next = NULL;
        return ret2;
    }

}