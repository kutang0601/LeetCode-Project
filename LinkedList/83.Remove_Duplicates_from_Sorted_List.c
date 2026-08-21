struct ListNode 
{
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head || !head->next)
    {
        return head;
    }
    
    struct ListNode* pcur = head;
    struct ListNode* plist = head->next;

    while (plist)
    {
        if (pcur->val == plist->val)
        {
            pcur->next = plist->next;
            plist = plist->next;
        }
        else
        {
            pcur = plist;
            plist = plist->next;
        }
    }

    return head;
}