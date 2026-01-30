//
// Created by Vier on 26-1-26.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> mp;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) mp[nums[i]]=1;
        for(int i = 0; i < nums.size(); i++) {
          if(mp[nums[i]]!=1) continue;
          int x=nums[i]+1;
          while(mp.find(x)!=mp.end()) {
            mp[nums[i]]+=mp[x];
            if(mp[x]!=1) break;
            mp[x++] = 0;
          }
          ans=max(ans, mp[nums[i]]);
        }
        return ans;
    }
};
int main() {

}