//
// Created by 17732 on 26-2-3.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
        int minn=1e5, ans=0;
		for (auto x : prices) {
			minn=min(minn,x);
			ans=max(ans, x - minn);
		}
		return ans;
	}
};