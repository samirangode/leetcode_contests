/**
  Definition for singly-linked list.
  **/
#include <bits/stdc++.h>;

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
    int pairSum(ListNode* head) {
    ListNode *first = head;
    vector<int> ll;
    while(first->next != NULL){
        ll.push_back(first->val);
        first = first->next;
    }
    //inverting a linkedlist
    int max = 0;
    int sum = 0;
    for(int i = 0; i< ll.size(); i++){
        sum = ll[i] + ll[ll.size()-i-1];
        if(sum>max){
            max = sum;
        }
    }
    return max;    
    }
};