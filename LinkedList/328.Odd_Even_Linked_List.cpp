struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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