//
// Created by 17732 on 26-1-30.
//
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (!head || !head->next) return nullptr;
        ListNode *fast = head->next, *slow = head;
		while (fast && fast->next && fast != slow) {
			fast = fast->next->next;
			slow = slow->next;
		}
		if (!fast || !fast->next) return nullptr;
		fast = head;
		slow = slow->next;
		while (fast != slow)
			fast = fast->next, slow = slow->next;
		return fast;
	}
};
int main() {
	ListNode *head = new ListNode(3);
	head->next = new ListNode(2);
	head->next->next = new ListNode(0);
	head->next->next->next = new ListNode(-4);
	head->next->next->next->next = head->next;
	Solution s;
	ListNode* x = s.detectCycle(head);
	if (x) printf("%d", x->val);
}