#include <stido.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
    if (!headA || !headB)
        return NULL;

    int n1 = 0;
    int n2 = 0;
    
    struct ListNode* plist1 = headA;
    struct ListNode* plist2 = headB;

    while (plist1)
    {
        n1++;
        plist1 = plist1->next;
    }
    while (plist2)
    {
        n2++;
        plist2 = plist2->next;
    }

    int x = n1 >= n2 ? n1 - n2 : n2 - n1;

    struct ListNode* much = headA;
    struct ListNode* few = headB;

    if (n2 > n1)
    {
        much = headB;
        few = headA;
    }

    while (x--)
    {
        much = much->next;
    }

    while (much)
    {
        if (much == few)
            return much;
        much = much->next;
        few = few->next;
    }

    return NULL;
}