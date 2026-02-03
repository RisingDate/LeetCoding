//
// Created by 17732 on 26-2-3.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool isValid(string s) {
		stack<char> st;
        int n = s.length();
		for (int i = 0; i < n; i++) {
			if (s[i] =='(' || s[i] =='{' || s[i] =='[') st.push(s[i]);
			else if (s[i] ==')' || s[i] =='}' || s[i] ==']') {
				if (st.empty()) return false;
				if (s[i] == ')' &&st.top() == '(') st.pop();
				else if (s[i] == '}' && st.top() == '{') st.pop();
				else if (s[i] == ']' && st.top() == '[') st.pop();
				else return false;
			}
		}
		if (!st.empty()) return false;
		return true;
	}
};