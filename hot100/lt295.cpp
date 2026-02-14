//
// Created by 17732 on 26-2-14.
//
#include<bits/stdc++.h>
using namespace std;
class MedianFinder1 {
public:
#define dd double
	priority_queue<int> q1;
	priority_queue<int, vector<int>, greater<int>> q2;
	MedianFinder1 () {
		while (!q1.empty()) q1.pop();
		while (!q2.empty()) q2.pop();
	}

	void addNum(int num) {
		if (q1.empty() && q2.empty()) q1.push(num);
		else if (q2.empty()) {
			int tmp = q1.top();
			if (tmp<num) q2.push(num);
			else {
				q2.push(q1.top());
				q1.pop();
				q1.push(num);
			}
		}
		else {
			if (q1.size() <= q2.size()) {
				if (num<q2.top()) q1.push(num);
				else {
					q1.push(q2.top());
					q2.pop();
					q2.push(num);
				}
			}
			else {
				if (num>q1.top()) q2.push(num);
				else {
					q2.push(q1.top());
					q1.pop();
					q1.push(num);
				}
			}
		}
	}

	double findMedian() {
		if (q1.size() == q2.size()) return (dd)(q1.top() + q2.top()) / 2;
		else if (q1.size() > q2.size()) return q1.top();
		else return q2.top();
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

class MedianFinder {
public:
#define dd double
	multiset<int> mt;
	multiset<int>::iterator mid;
	MedianFinder() {
		mt.clear();
		mid = mt.begin();
	}
	void addNum(int num) {
		int n=mt.size();
		mt.insert(num);
		if (n==0) mid=mt.begin();
		else if (num<*mid&&n&1) --mid;
		else if (num>=*mid&&!(n&1)) ++mid;
	}
	double findMedian() {
		if (mt.size()&1) return *mid;
		else return (dd)(*mid + *next(mid)) / 2;
	}
};