#include <bits/stdc++.h>

using namespace std;


//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 1; ListNode* kth = head;
        ListNode* temp = head;
        while(temp->next!=nullptr){
            n++;
            if(n==k) kth = temp;
            temp = temp->next;
            
        }
        temp = kth; int i = k;
        while(i<=n-k){
            i++;
            if(i == n-k) break;
            temp = temp->next; 
        }
        ListNode* k_next = kth->next; 
    }
};
