//
// Created by 17732 on 26-2-4.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool judge(string word, string s, int x) {
		for (int i=0; i<word.length(); i++)
			if (word[i] != s[i+x]) return false;
		return 1;
	}
	bool wordBreak(string s, vector<string>& wordDict) {
		vector<bool> dp(s.size() + 1, false);
		for (int i = 0; i < s.size(); i++) {
			for (auto word : wordDict) {
				int len = word.length();
				if ((i-len ==-1 || (i>=len && dp[i-len])) && judge(word, s, i-len+1)) {
					dp[i] = true;
					break;
				}
			}
		}
		return dp[s.size()-1];
	}
};
