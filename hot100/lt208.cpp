//
// Created by 17732 on 26-2-1.
//
#include<bits/stdc++.h>
using namespace std;
class Trie {
struct TrieNode {
	bool isEnd;
	TrieNode *children[26];
	TrieNode() {
		isEnd = false;
		for (int i = 0; i < 26; i++) children[i] = nullptr;
	}
}*root;
public:
	Trie() {
		this->root = new TrieNode();
	}

	void insert(string word) {
		TrieNode* cur = this->root;
		for (int i=0;i<word.size();i++) {
			if (!cur->children[word[i]-'a'])
				cur->children[word[i]-'a'] = new TrieNode();
			cur = cur->children[word[i]-'a'];
		}
		cur->isEnd = true;
	}

	bool search(string word) {
		TrieNode* cur = this->root;
		for (int i=0;i<word.size();i++) {
			if (!cur->children[word[i]-'a']) return false;
			cur = cur->children[word[i]-'a'];
		}
		return cur->isEnd;
	}

	bool startsWith(string prefix) {
		TrieNode* cur = this->root;
		for (int i=0;i<prefix.size();i++) {
			if (!cur->children[prefix[i]-'a']) return false;
			cur = cur->children[prefix[i]-'a'];
		}
		return true;
	}
};
