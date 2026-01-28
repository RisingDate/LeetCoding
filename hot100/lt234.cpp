//
// Created by Vier on 26-1-28.
//
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        ListNode *p=head;
        ListNode *q=head;
        if(head->next) q=q->next;
        else return head;
        while(q->next&&q->next->next)
            p=p->next, q=q->next->next;

        ListNode *mid;
        if(q->next) {
            q=q->next;
            mid=p->next->next;
            p->next=nullptr;
        }
        else {
            mid=p->next;
            p->next=nullptr;
        }

        // reverse
        ListNode *pre=nullptr;
        ListNode *nxt=nullptr;
        while(mid) {
            nxt=mid->next;
            mid->next=pre;
            pre=mid;
            mid=nxt;
        }

        p = head;
        while(q&&p) {
            if(q->val!=p->val) return 0;
            p=p->next, q=q->next;
        }
        if(p==nullptr&&q==nullptr) return 1;
        else return 0;
    }
};

int main() {
    ListNode *p = new ListNode(1);
    p->next = new ListNode(2);
    p->next->next = new ListNode(2);
    p->next->next->next = new ListNode(1);
    Solution s;
    bool res = s.isPalindrome(p);
    printf("%d", res);
    return 0;
}