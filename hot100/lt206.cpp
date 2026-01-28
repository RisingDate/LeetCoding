//
// Created by 17732 on 26-1-28.
//
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode *p = nullptr, *q = head;
		while (q != nullptr) {
			ListNode *tmp = q->next;
			q->next = p;
			p=q;
			q=tmp;
		}
		return p;
	}
};