//
// Created by 17732 on 26-2-11.
//
#include<bits/stdc++.h>
using namespace std;
class LRUCache {
public:
	struct Node {
		int key;
		int value;
		Node* pre;
		Node* next;
		Node():key(-1),value(-1), next(nullptr){}
		Node(int key, int value):key(key), value(value), next(nullptr){}
	};
	int size;
	int tmpNum;
	unordered_map<int,Node*> um;
	Node* head;
	Node* tail;
	LRUCache(int capacity) {
		size=capacity;
		tmpNum=0;
		head = new Node();
		tail = head;
	}

	int get(int key) {
		if(um.find(key)!=um.end()) {
			Node* p = um[key];
			moveToTail(p);
			return p->value;
		}
		return -1;
	}

	void put(int key, int value) {
		if (um.find(key)!=um.end()) um[key]->value = value, moveToTail(um[key]);
		else {
			if (tmpNum<size) tmpNum++;
			else {
				Node *p = head->next;
				p->pre->next = p->next;
				if (p->next) p->next->pre = p->pre;
				else tail=head;
				um.erase(p->key);
			}
			addToTail(key, value);
		}
	}
	void moveToTail(Node* p) {
		if (p==tail) return ;
		Node* pre = p->pre;
		pre->next = p->next;
		if (p->next) p->next->pre = pre;

		tail->next = p;
		p->pre = tail;
		tail = tail->next;
	}
	void addToTail(int key, int value) {
		Node* newNode = new Node(key, value);
		um[key] = newNode;
		tail->next = newNode;
		newNode->pre = tail;
		tail = tail->next;
	}
};
int main() {
	LRUCache lRUCache(1);
	cout<<lRUCache.get(6)<<endl;
	cout<<lRUCache.get(8)<<endl;
	lRUCache.put(12, 1);
	cout<<lRUCache.get(2)<<endl;
	lRUCache.put(15, 1);
	lRUCache.put(5, 2);
	lRUCache.put(1, 15);
	lRUCache.put(4, 2);
	cout<<lRUCache.get(4)<<endl;
	lRUCache.put(15, 15);
}