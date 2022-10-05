#include <bits/stdc++.h>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
 
//     }
//     void dfs(TreeNode* root, TreeNode* p, TreeNode* q, bool &p_found, bool &q_found, bool &first_time){
//         if(root == NULL) return;
//         if(root->val == p->val){
//             p_found = true;
//         }
//         if(root->val== q->val){
//             q_found = true;
//         }

//         dfs(root->left, p, q, p_found, q_found, first_time);
//         dfs(root->right, p, q, p_found, q_found, first_time);
//         if(p_found && q_found && first_time){
            
//         }
//     }
// };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if((root->val > p->val) && (root->val>q->val)){
            return lowestCommonAncestor(root->left, p, q);
        }
        if((root->val < p->val) && (root->val < q->val)){
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;      
    }
};
