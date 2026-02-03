//
// Created by Vier on 26-2-4.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size(),ans=0;
        for(int i=0;i<n;i++) ans^=nums[i];
        return ans;
    }
};