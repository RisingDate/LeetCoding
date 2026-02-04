//
// Created by 17732 on 26-2-4.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	string longestPalindrome(string pre_s) {
		string s="", ans="";
		for(int i=0;i<pre_s.length();i++) s+='#',s+=pre_s[i];
		s+='#';
		int n = s.size();
		for (int i=0; i<n ;i++) {
			int l=i,r=i;
			while (l>=0&&r<n && s[l]==s[r])
				--l,++r;
			if (r-l-1>ans.length()) ans=s.substr(l+1,r-l-1);
		}
		string res = "";
		for (int i=0; i<ans.length(); i++)
			if (ans[i]!='#') res+=ans[i];
		return res;
	}
};