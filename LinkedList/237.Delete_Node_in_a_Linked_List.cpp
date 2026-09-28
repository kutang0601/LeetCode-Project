struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//直接将要修改的值改为下一个值，并且指向下下一个节点
//时间度杂毒：O(1)
class Solution
{
    public:
        void deleteNode(ListNode* node)
        {
            node->val = node->next->val;
            node->next = node->next->next;
        }
};