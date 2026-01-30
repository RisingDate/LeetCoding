//
// Created by 17732 on 26-1-30.
//
#include<bits/stdc++.h>
using namespace std;
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = nullptr;
		random = nullptr;
	}
};

class Solution {
public:
	Node* copyRandomList(Node* head) {
		unordered_map<Node*, Node*> mp;
		if (head == nullptr) return nullptr;
		Node* newHead = new Node(head->val);
		mp[head] = newHead;
		Node* newTail = newHead;
		while (head) {
			if (head->next && mp.find(head->next) == mp.end()) {
				Node *p = new Node(head->next->val);
				mp[head->next] = p;
				newTail->next = p;
			}
			else newTail->next = mp[head->next];
			if (head->random && mp.find(head->random) == mp.end()) {
				Node *p = new Node(head->random->val);
				mp[head->random] = p;
				newTail->random = p;
			}
			else newTail->random = mp[head->random];

			head = head->next;
			newTail = newTail->next;
		}
		return newHead;
	}
};