class Solution {
public:
struct node {
	int count;
	int val;
	int left_cnt;
	node * left, *right;
	node(int v) {
		val = v; 
		count = 1;
		left_cnt = 0;
		left = NULL;
		right = NULL;
	}
};
int insert(int val, node *&head) {
	node * p = head;
	int cnt = 0;
	if (head == NULL)
		head = new node(val);
	while (p) {
		if (p->val > val) {
			p->left_cnt++;
			if (p->left == NULL) {
				p->left = new node(val);
				break;
			}
			p = p->left;
		}
		else if (p->val < val) {
			cnt += p->left_cnt + p->count;
			if (p->right == NULL) {
				p->right = new node(val);
				break;
			}
			p = p->right;
		}
		else {
			cnt += p->left_cnt;
			p->count++;
			break;
		}
	}
	return cnt;
}

vector<int> countSmaller(vector<int>& nums) {
	node * head = NULL;
	int a;
	vector<int> res;
	res.resize(nums.size());
	for (int i = nums.size() - 1; i > -1; i--) {
		res[i] = insert(nums[i], head);
	}
	return res;
}
};