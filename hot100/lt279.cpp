// Created by 17732 on 26-2-4
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int numSquares(int n) {
		vector<int> sq;
		vector<int> dp(n + 1, 1e5);
		dp[0] = 0, dp[1] = 1;
		for(int i=1; i<=n; i++){
			int x=sqrt(i);
			if (x*x == i) sq.push_back(i), dp[i]=1;
			else for (auto j : sq)
				dp[i] = min(dp[i], dp[i-j]+1);
		}
		return dp[n];
	}
};