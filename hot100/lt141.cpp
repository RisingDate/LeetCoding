//
// Created by Vier on 26-1-29.
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
	bool hasCycle(ListNode *head) {
		int cnt=0;
		while(head) {
			head = head->next;
			if(++cnt > 1e4+5) break;
		}
		if(head) return true;
		return false;
	}
};