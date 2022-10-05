#include <bits/stdc++.h>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
////////////// Morris Traversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr;
        TreeNode* prev;
        curr = root;
        vector<int> ans;
        while(curr!=NULL){
            // left is null, explore current node and move right
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                prev = curr->left;
                // go to the right most node
                while(prev->right!=NULL && prev->right!=curr){
                    prev = prev->right;
                }
                // if null set it to the parent
                if(prev->right==NULL){
                    prev->right = curr;
                    curr = curr->left;
                }// if already visited, set it back to null and print curr
                else{
                    prev->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }

            }
        }
        return ans;
    }
};
