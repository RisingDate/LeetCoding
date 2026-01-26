//
// Created by Vier on 26-1-26.
//
#include<cstdio>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* tail = ans;
        int flag = 0;
        while(l1 && l2) {
            ListNode* newNode = new ListNode();
            newNode->val = (l1->val + l2->val + flag) % 10;
            flag = (l1->val + l2->val + flag) / 10;
            tail->next = newNode;
            tail = newNode;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            ListNode* newNode = new ListNode();
            newNode->val = (l1->val + flag) % 10;
            flag = (l1->val + flag) / 10;
            tail->next = newNode;
            tail = newNode;
            l1 = l1->next;
        }
        while(l2) {
            ListNode* newNode = new ListNode();
            newNode->val = (l2->val + flag) % 10;
            flag = (l2->val + flag) / 10;
            tail->next = newNode;
            tail = newNode;
            l2 = l2->next;
        }
        if(flag)
            tail->next = new ListNode(1);
        return ans->next;
    }
};

int main() {
    Solution s;
    ListNode* l1 = new ListNode();
    l1->val = 9;
    l1->next = new ListNode(6);
    ListNode* l2 = new ListNode();
    l2->val = 1;
    l2->next = new ListNode(3);
    ListNode* ans = s.addTwoNumbers(l1, l2);
    while(ans) printf("%d", ans->val), ans=ans->next;
}
