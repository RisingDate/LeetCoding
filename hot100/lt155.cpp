//
// Created by 17732 on 26-2-3.
//
#include<bits/stdc++.h>
using namespace std;
class MinStack {
	struct node{
		int x,minn;
	};
private:
	stack<node> s;
public:
	MinStack() {

	}

	void push(int val) {
		if(s.empty()) s.push({val,val});
		else s.push({val,min(val,s.top().minn)});
	}

	void pop() {
		s.pop();
	}

	int top() {
		return s.top().x;
	}

	int getMin() {
		return s.top().minn;
	}
};