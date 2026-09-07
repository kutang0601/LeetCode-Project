struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//先寻找中间节点，然后反转链表，最后前一个后一个合并链表
//时间复杂度：O(n)
class Solution 
{
    public:
        void reorderList(ListNode* head) 
        {
            //两个及以下不需要处理
            if (!head || !head->next || !head->next->next)
            {
                return;
            }

            //寻找中间节点
            struct ListNode* fast = head;
            struct ListNode* slow = head;
            struct ListNode* prev = nullptr;
            while (fast != nullptr && fast->next != nullptr)
            {
                fast = fast->next->next;
                prev = slow;
                slow = slow->next;
            }

            prev->next = nullptr;

            //从中间节点开始反转链表
            struct ListNode* phead = nullptr;
            struct ListNode* pcur = slow;
            struct ListNode* ptail = slow->next;
            while (ptail)
            {
                pcur->next = phead;
                phead = pcur;
                pcur = ptail;
                ptail = ptail->next;
            }
            pcur->next = phead;

            struct ListNode* plist = head;
            head = head->next;

            //合并链表
            while (head)
            {
                struct ListNode* temp1 = pcur->next;
                struct ListNode* temp2 = head->next;

                plist->next = pcur;
                plist->next->next = head;

                pcur = temp1;
                head = temp2;

                plist = plist->next->next;
            }

            while (pcur)
            {
                struct ListNode* temp = pcur->next;
                plist->next = pcur;
                pcur = temp;
                plist = plist->next;
            }

            return;
        }
};