//
// Created by 17732 on 26-2-3.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	string intToStr(int num) {
		string res = "";
		while (num != 0) res += char(num % 10 + '0'), num /= 10;
		reverse(res.begin(), res.end());
		return res;
	}
	int str2Int(string s) {
		int res = 0;
		for (int i = 0; i < s.length(); i++)
			res = res * 10 + s[i] - '0';
		return res;
	}
	bool isNum(string s) {
		return s[0]>='0' && s[0]<='9';
	}
	string strRepeat(string s, int num) {
		string res = "";
		while (num--)
			res += s;
		return res;
	}
	string decodeString(string s) {
		stack<string> st;
		int num=0;
		string tmpS = "";
		for (int i = 0; i < s.length(); i++) {
			if (s[i]>='0' && s[i]<='9')
				num = num*10 + (s[i]-'0');
			else if (s[i]=='[') {
				st.push(intToStr(num));
				num=0;
			}
			else if (s[i]==']') {
				while (!st.empty()&&!isNum(st.top())) {
					tmpS = st.top()+tmpS;
					st.pop();
				}
				tmpS = strRepeat(tmpS, str2Int(st.top()));
				st.pop();
				while (!st.empty()&&!isNum(st.top())) {
					tmpS = st.top()+tmpS;
					st.pop();
				}
				st.push(tmpS);
				tmpS="";
			}
			else {
				string tmp = "";
				st.push(tmp+s[i]);
			}
		}
		string ans = "";
		while (!st.empty()) {
			ans = st.top() + ans;
			st.pop();
		}
		return ans;
	}
};
int main() {
	Solution s;
	string str = "3[ab]2[a]";
	cout<<s.decodeString(str)<<endl;
}