struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//偶节点添加到一个链表，奇节点添加到一个链表，偶节点的头和奇节点的尾相连，并且将尾节点的 next 置空
//时间复杂度：O(n) 
class Solution 
{
    public:
        ListNode* oddEvenList(ListNode* head) 
        {
            if (!head || !head->next)
                return head;

            ListNode* newhead = nullptr;
            ListNode* newtail = nullptr;

            ListNode* phead = nullptr;
            ListNode* ptail = nullptr;

            int count = 1;

            while (head)
            {
                if (count % 2 == 1)
                {
                    if (!newhead)
                    {
                        newhead = head;
                        phead = head;
                    }
                    else 
                    {
                        phead->next = head;
                        phead = phead->next;
                    }                
                }
                else
                {
                    if (!newtail)
                    {
                        newtail = head;
                        ptail = head;
                    }
                    else 
                    {
                        ptail->next = head;
                        ptail = ptail->next;
                    }
                }

                count++;
                head = head->next;
            }

            phead->next = newtail;
            ptail->next = nullptr;

            return newhead;
        }
};