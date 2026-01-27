//
// Created by 17732 on 26-1-27.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	queue<char> q;
	bool inq[1001];
	int ans=0;
	int lengthOfLongestSubstring(string s) {
		for (int i = 0; i < s.length(); i++) {
			if (inq[s[i]]) {
				while (!q.empty() && q.front() != s[i]) q.pop();
				q.pop();
			}
			q.push(s[i]);
			ans = max(ans, (int)q.size());
		}
	}
};
int main() {

}