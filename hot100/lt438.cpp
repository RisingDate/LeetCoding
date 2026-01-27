//
// Created by 17732 on 26-1-27.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int numS[26], numP[26];
	bool check() {
		for (int i = 0; i < 26; i++)
			if (numP[i] != numS[i]) return 0 ;
		return 1;
	}
	vector<int> findAnagrams(string s, string p) {
		queue<int> q;
		vector<int> ans;
		for (int i=0;i<p.length();i++) numP[p[i]-'a']++;
		for (int i=0;i<s.length();i++) {
			q.push(s[i]);
			numS[s[i]-'a']++;
			if (q.size()>p.length()) numS[q.front()-'a']--, q.pop();
			if (i>=p.length()-1 && check()) ans.push_back(i - p.length() + 1);
		}
		return ans;
	}
};
int main() {

}