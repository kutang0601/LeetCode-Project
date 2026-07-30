#include <stdlib.h>

struct ListNode 
{
    int val;
    struct ListNode *next;
};


struct ListNode* swapPairs(struct ListNode* head) 
{
    if (!head || !(head->next))
        return head;
    
    struct ListNode* first = head;
    struct ListNode* seconde = head->next;
    struct ListNode* tmp = head;
    head = seconde;

    struct ListNode* prev = NULL;

    while (first->next->next && seconde->next->next)
    {
        first->next = seconde->next;
        seconde->next = first;

        if (first != tmp)
            prev->next = seconde;

        prev = first;
        seconde = first->next->next;
        first = first->next;
    }

    first->next = seconde->next;
    seconde->next = first;

    if (prev)
        prev->next = seconde;

    return head;
}