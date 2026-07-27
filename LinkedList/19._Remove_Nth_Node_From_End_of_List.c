#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
  if (!head || !(head->next))
    return NULL;

  int lenth = 0;
  struct ListNode *pcur = head;
  while (pcur) {
    pcur = pcur->next;
    lenth++;
  }

  struct ListNode *plist = NULL;
  pcur = head;
  int lenth1 = lenth - n;

  if (lenth1 == 0) {
    head = pcur->next;
    free(pcur);
    return head;
  }

  while (lenth1--) {
    plist = pcur;
    pcur = pcur->next;
  }

  plist->next = pcur->next;
  free(pcur);

  return head;
}

// 代码思路优化
// 先创建一个哑节点，然后快慢指针解决
struct ListNode *PremoveNthFromEnd(struct ListNode *head, int n) {
  struct ListNode dummy;
  dummy.next = head;

  struct ListNode *fast = &dummy, *slow = &dummy;

  // 先让fast指针走N
  for (int a = 0; a < n; a++) {
    fast = fast->next;
  }

  // 然后快慢指针一直走，等fast为空，slow 为删除节点前驱
  while (fast->next) {
    fast = fast->next;
    slow = slow->next;
  }

  struct ListNode *tmp = slow->next;
  slow->next = tmp->next;

  struct ListNode *newhead = dummy.next;

  return newhead;
}