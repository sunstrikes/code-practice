/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
ListNode* reverseKGroup(ListNode* head, int k) {
	ListNode * begin = new ListNode(0);
	begin->next = head;
	ListNode *p, *p1, *p2;
	p = begin;
	while (p->next) {
		ListNode *x = p->next;
		bool flag = true;
		for (int i = 0; i < k; i++) {
			if (x == NULL) {
				flag = false;
				break;
			}
			x = x->next;
		}
		if (flag) {
			p1 = p->next;
			if (p1)
				p2 = p1->next;
			else
				break;
			ListNode * tail = p1;
			for (int i = 1; i < k; i++) {
				ListNode *tmp = p2->next;
				p2->next = p1;
				p1 = p2;
				p2 = tmp;
			}
			tail->next = p2;
			p->next = p1;
			p = tail;
		}else{
			break;
		}
	}
	return begin->next;
}
};