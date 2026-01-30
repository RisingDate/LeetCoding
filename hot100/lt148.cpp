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
	ListNode* merge(ListNode* p, ListNode* q) {
		ListNode* preHead = new ListNode(0);
		ListNode* tmp = preHead, *p1 = p, *p2 = q;
		while (p1 || p2) {
			if (!p2 || p1 && p1->val <= p2->val) tmp->next = p1, tmp=tmp->next, p1 = p1->next;
			else tmp->next = p2, tmp=tmp->next, p2 = p2->next;
		}
		return preHead->next;
	}
	ListNode* sortList(ListNode* head) {
		ListNode* preHead = new ListNode(0, head);
		ListNode* p = head;
		int n=0;
		while (p)  p = p->next, ++n;
		if (n < 2) return head;
		int len = 1;
		while (len < n) {
			ListNode* pre = preHead;
			p = pre->next;
			while (p) {
				ListNode* h1 = p;
				for (int i=1; i<len && p->next; i++) p = p->next;
				ListNode* h2 = p->next;
				p->next = nullptr;
				p = h2;
				for (int i=1; i<len && p && p->next; i++) p = p->next;
				ListNode* nxt = nullptr;
				if (p) {
					nxt = p->next;
					p->next = nullptr;
				}
				ListNode* meg = merge(h1, h2);
				pre->next = meg;

				while (pre->next) pre = pre->next;
				p = nxt;
			}
			len<<=1;
		}
		return preHead->next;
	}
};