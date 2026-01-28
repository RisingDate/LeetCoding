//
// Created by 17732 on 26-1-28.
//
#include<bits/stdc++.h>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		unordered_set<ListNode*> st;
		while (headA) st.insert(headA), headA = headA->next;
		while (headB) {
			if (st.find(headB) != st.end()) return headB;
			headB = headB->next;
		}
		return NULL;
	}
};
