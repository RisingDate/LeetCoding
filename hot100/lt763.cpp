//
// Created by 17732 on 26-2-3.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> partitionLabels(string s) {
		vector<pair<int, int> > pos(26, {s.length(), 0});
		for (int i = 0; i < s.length(); i++) {
			pos[s[i] - 'a'].first = min(pos[s[i] - 'a'].first, i);
			pos[s[i] - 'a'].second = max(pos[s[i] - 'a'].second, i);
		}
		int l=pos[s[0]-'a'].first, r=pos[s[0]-'a'].second;
		vector<int> ans;
		for (int i = 0; i < s.length(); i++) {
			if (i==s.length()-1) ans.push_back(i-l+1);
			else if (i==r) {
				ans.push_back(r-l+1);
				l=pos[s[i+1]-'a'].first, r=pos[s[i+1]-'a'].second;
			}
			if (r<pos[s[i]-'a'].second) r=pos[s[i]-'a'].second;
		}
		return ans;
	}

	vector<int> partitionLabels2(string s) {
		vector<vector<bool> > a(s.length() + 1);
		vector<bool> tmp(26, 0);
		vector<int> ans;
		a[s.size()] = tmp;
		for (int i = s.length() - 1; i >= 0; i--) {
			tmp[s[i] - 'a'] = 1;
			a[i] = tmp;
		}
		int l = 0, r = 0;
		vector<bool> in(26, 0);
		for (int i = 0; i < s.length(); i++) {
			in[s[i] - 'a'] = 1;
			bool isSep = 1;
			for (int j = 0; j < 26; j++) {
				if (in[j] && a[i + 1][j]) {
					isSep = 0;
					break;
				}
			}
			if (isSep) {
				ans.push_back(r - l + 1);
				l = r = i + 1;
				in.clear();
			} else {
				++r;
			}
		}
		return ans;
	}
};

int main() {
	Solution s;
	string str = "caedbdedda";
	vector<int> ans = s.partitionLabels(str);
	for (auto x: ans) cout << x << " ";
}
