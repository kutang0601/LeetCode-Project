#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
 };
 
 
//先找到中间节点
//然后从中间反转连表
//最后两个指针的val表较大小
bool isPalindrome(struct ListNode* head) {
    if (!head || !head->next)
        return true;
 
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    
    //找到中间节点
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
 
    struct ListNode* pcur = NULL;
    
    //反转
    while(slow)
    {
        struct ListNode* tmp = slow->next;
        slow->next = pcur;
        pcur = slow;
        slow = tmp;
    }
 
    struct ListNode* phead = head;
    
    while (pcur)
    {
        if (pcur->val != phead->val)
            return false;
        pcur = pcur->next;
        phead = phead->next;
    }
         
    return true;
}