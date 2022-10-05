
#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ListNode* next = head;
        bool over = false;
        int top = 0, bottom = m-1;
        int left = 0, right = n-1;
        int val = 0;
        bool done = false;
        vector<vector<int>> ans(m,vector<int>(n,-1));
        while(next!=NULL){
            cout<<"in here"<<endl;
            if(left > right) break;
            for(int i = left; i<=right; i++){
                if(next==NULL){ done =true; return ans;}
                ans[top][i] = next->val;
                next = next->next;
            }
            if(done) break;
            top++;
            if(top>bottom) break;
            for(int i = top; i<=bottom; i++){
                if(next == NULL) { done =true; return ans;}
                ans[i][right] = next->val;
                next = next->next;
            }
            if(done) break;
            
            right--;
            if(left>right) break;
            for(int i = right; i>=left; i--){
                if(next == NULL) { done =true; return ans;}
                ans[bottom][i] = next -> val;
                next = next->next;
            }
            if(done) break;
            
            bottom++;
            if(top>bottom) break;
            for(int i = bottom; i>=top; i--){
                if(next == NULL) { done =true; return ans;}
                ans[i][left] = next -> val;
                next = next->next;
            }
            if(done) break;
            
            left ++;
            // next->next;
        }
        return ans;  
    }
};

