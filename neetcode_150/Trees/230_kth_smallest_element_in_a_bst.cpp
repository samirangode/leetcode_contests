#include<bits/stdc++.h>

using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* curr = root;
        // long long max_val =LONG_LONG_MIN;
        int num = 0;
        while(curr!=NULL || !s.empty()){
            while(curr!=NULL){
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop(); num++;
            if(num==k) return curr->val; 
            // if(curr->val <= max_val) return false;
            // max_val = max(max_val, 1ll*curr->val);
            curr = curr->right;
        }
        return -1;
    }
};

