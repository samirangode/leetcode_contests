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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        int j = 0;
        vector<int> ans;
        vector<vector<int>> tempVec;
        TreeNode* temp;
        if(root==nullptr) return tempVec;
        while(!q.empty()){
            // ans.clear();
            temp = q.front();
            q.pop(); i--;
            ans.push_back(temp->val);
            
            if(temp->left != nullptr){
                q.push(temp->left);
                j++;
            }
            if(temp->right != nullptr){
                q.push(temp->right);
                j++;
            }
            if(i==0){
                tempVec.push_back(ans);
                ans.clear();
                i = j;
                j = 0;
            }
        }
        return tempVec;    
    }
};