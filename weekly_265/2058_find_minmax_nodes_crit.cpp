#include <bits/stdc++.h>

using namespace std;

/**
 **/ //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 /**/
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
       ListNode* prev;
       prev = head;
       ListNode* curr = head->next;
       ListNode* nex = curr->next;
       int min_d = INT_MAX;
       vector<int> vec;
       int i = 1;
       int n = 0;
       while(nex-> next != NULL){
           int a = prev->val;
           int b = curr-> val;
           int c = nex->val;
           if((a<b && b>c)|| (a>b && b<c)){
               vec.push_back(i);
               n = vec.size();
               if(n>1){
                   min_d = min(min_d, vec[n-1]-vec[n-2]);
               }
           }
           i++;
           prev = prev->next;
           curr = curr->next;
           nex = nex->next;
       }
       n = vec.size();
       vector<int> ans;
       if(n>1){
            ans = {min_d,vec[n-1]-vec[0]};
       }else{
           ans = {-1,-1};
       }
        return ans;
    }
};