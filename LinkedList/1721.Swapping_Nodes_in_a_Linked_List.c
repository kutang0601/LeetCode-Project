struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *swapNodes(struct ListNode *head, int k) {
  if (!head || !(head->next))
    return head;

  int lenth = 0;
  struct ListNode *plist = head;
  while (plist) {
    plist = plist->next;
    lenth++;
  }

  lenth -= k;
  struct ListNode *pcur = head;

  while (lenth--) {
    pcur = pcur->next;
  }

  struct ListNode *seconde = pcur;
  struct ListNode *first = head;

  while (pcur->next) {
    pcur = pcur->next;
    first = first->next;
  }

  int tmp = first->val;
  first->val = seconde->val;
  seconde->val = tmp;

  return head;
}