//
// Created by Vier on 26-1-26.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string numComplete(int num) {
        string res = "";
        if(num<100) res += '0';
        if(num<10) res += '0';
        res += num;
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int> mp;
        vector<vector<string>> ans;
        int a[27];
        int cnt = 0;
        for(int i=0;i<strs.size();i++) {
            memset(a,0,sizeof a);
            string s = strs[i];
            for(int i=0;i<s.length();i++)
                a[s[i]-'a']++;
            string hash_a = "";
            for(int i=0;i<27;i++) hash_a += numComplete(a[i]);

            int pos = 0;
            if(mp.find(hash_a)==mp.end()) mp[hash_a] = pos = cnt++;
            else pos = mp[hash_a];

            if(ans.size()<cnt) ans.push_back({});
            ans[pos].push_back(s);
        }
        return ans;
    }
};
int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;
    s.groupAnagrams(strs);
}