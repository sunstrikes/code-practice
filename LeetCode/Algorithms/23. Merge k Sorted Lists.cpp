 class Solution {
 public:
	 ListNode * mergeKLists(vector<ListNode*>& lists) {
		 ListNode *start = nullptr;
		 ListNode *now = nullptr;
		 auto cmp = [](ListNode* l, ListNode* r) {return l->val > r->val; };
		 std::priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
		 for (auto &t : lists) {
			 if (t)
                pq.push(t);
		 }
		 while (!pq.empty()) {
			 auto t = pq.top();
			 pq.pop();
			 //cout << t->val << endl;
			 if (t->next != nullptr) {
				 pq.push(t->next);
			 }
			 if (start == nullptr) {
				 start = t;
				 now = t;
			 }
			 else {
				 now->next = t;
				 now = now->next;
			 }
		 }
		 return start;
	 }
 };