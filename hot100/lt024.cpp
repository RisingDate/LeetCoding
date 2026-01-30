//
// Created by 17732 on 26-1-30.
//
#include<bits/stdc++.h>
using namespace	std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode* preHead = new ListNode(0, head);
        ListNode* tag = preHead;;
		while (tag->next && tag->next->next) {
			ListNode* p = tag->next;
			ListNode* q = p->next;
			p->next = q->next;
			tag->next = q;
			q->next = p;
			tag = tag->next->next;
		}
		return preHead->next;
	}
};