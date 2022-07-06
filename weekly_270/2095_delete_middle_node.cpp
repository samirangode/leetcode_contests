#include <bits/stdc++.h>
#include <iostream>

using namespace std;



  //Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* middle;
        ListNode* end;
        ListNode* prev;
        if(head==NULL){
            return head;
        }
        if(head->next == NULL){
            return NULL;
        }
        int i = 0;
        end = head;
        middle = head;
        prev = middle;
        while(end!=NULL && end->next != NULL){
            end = (end->next)->next;
            prev = middle;
            middle = middle->next;
            i++;

        }
        if(i%2==0){
            prev = prev->next;
            middle = middle-> next;
            prev->next = middle->next;
        }
        else{
            prev->next = middle->next;
        }
        return head;
    }
};