//
// Created by Vier on 26-1-27.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1;
        int maxArea = 0;
        for(int h=1; h<1e4; h++) {
            while(l<r && height[l]<h) ++l;
            while(l<r && height[r]<h) --r;
            maxArea = max(maxArea, (r-l)*h);
        }
        return maxArea;
    }
};
int main() {

}