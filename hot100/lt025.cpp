//
// Created by 17732 on 26-4-8.
//
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(){val=0; next=nullptr;}
	ListNode(int v):val(v),next(nullptr){}
};
class Solution {
public:
	ListNode* getNextP(ListNode* p, int k) {
		for (int i=0;i<k;i++) if (p) p=p->next;
		return p;
	}
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (!head) return nullptr;
		ListNode* p=nullptr;
		ListNode* q=head;
		ListNode* nextP=getNextP(head,k-1);
		ListNode* res=head;
		ListNode* preTail = p;
		while (nextP) {
			ListNode* tmpHead=q;
			while (p!=nextP) {
				ListNode* tmp=q;
				q=q->next;
				tmp->next=p;
				p=tmp;
			}
			if (res==head&&k!=1) res=p;
			nextP = getNextP(q, k-1);
			if (preTail) preTail->next=p;
			preTail=tmpHead;
		}
		preTail->next=q;
		return res;
	}
};

// 辅助函数：根据数组（样例）创建链表
ListNode* createList(const vector<int>& arr) {
	if (arr.empty()) return nullptr;
	ListNode* head = new ListNode(arr[0]);
	ListNode* curr = head;
	for (size_t i = 1; i < arr.size(); ++i) {
		curr->next = new ListNode(arr[i]);
		curr = curr->next;
	}
	return head;
}

void printList(ListNode* head) {
	while (head) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << "nullptr" << endl;
}

int main() {
	// 1. 按照样例准备数据：head = [1,2,3,4,5]
	int k=1;
	vector<int> nums = {1, 2, 3, 4, 5};
	ListNode* head = createList(nums);

	// 2. 打印反转前的链表
	cout << "反转前: ";
	printList(head);

	// 3. 执行反转逻辑
	Solution sol;
	ListNode* reversedHead = sol.reverseKGroup(head, k);

	// 4. 打印反转后的链表验证结果
	cout << "反转后: ";
	printList(reversedHead);

	return 0;
}