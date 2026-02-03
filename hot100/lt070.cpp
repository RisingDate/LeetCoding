//
// Created by Vier on 26-2-4.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        vector<int> f = {1,2};
        for(int i=2; i<n; i++) f.push_back(f[i-1] + f[i-2]);
        return f[n-1];
    }
};