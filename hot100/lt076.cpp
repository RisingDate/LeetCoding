//
// Created by 17732 on 26-2-12.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	string minWindow(string s, string t) {
		vector<int> count(123, 0);
		set<int> st;
		string ans="";
		for (int i=0; i<t.size(); i++)
			st.insert(t[i]), count[t[i]]++;
		int l=0, r=0, n=s.length();
		while (r<=n) {
			bool inq=0;
			for (int i='A'; i<='z'; i++)
				if (count[i]>0){inq=1; break;}
			if (inq) {
				if (st.find(s[r])!=st.end()) count[s[r]]--;
				++r;
			}
			else {
				while (st.find(s[l])==st.end() || count[s[l]]+1<=0) {
					if (st.find(s[l])!=st.end()) count[s[l]]++;
					++l;
				}
				if (ans=="") ans = s.substr(l, r-l);
				else if (ans.length() > r-l) ans = s.substr(l, r-l);
				count[s[l]]++;
				++l;
			}
		}
		return ans;
	}
};
int main() {
	Solution sol;
	string s = "ADOBECODEBANC", t="ABC";
	string ans = sol.minWindow(s, t);
	cout<<ans;
}