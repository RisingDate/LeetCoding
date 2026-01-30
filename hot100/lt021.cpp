//
// Created by 17732 on 26-1-30.
//
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode *head = new ListNode(0);
		ListNode *tail = head;
		while (list1 || list2) {
			int val1,val2;
			if (list1) val1 = list1->val;
			else val1=200;
			if (list2) val2 = list2->val;
			else val2=200;
			if (val1<val2) {
				tail->next = new ListNode(val1);
				if (val1<200) list1 = list1->next;
			}
			else {
				tail->next = new ListNode(val2);
				if (val2<200) list2 = list2->next;
			}
			tail = tail->next;
		}
		return head->next;
	}
};