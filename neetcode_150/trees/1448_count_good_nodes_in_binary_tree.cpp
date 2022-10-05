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
 
// class Solution {
// public:
//     multiset<int> s;
//     int ans = 0;
//     int goodNodes(TreeNode* root) {
//         recursive(root);
//         return ans;
//     }
//     void recursive(TreeNode* root){
//         if(root==NULL) return;
//         if(!s.empty()){
//             int max = *(s.rbegin());
//             if(root->val >= max) ans++;
            
//         }else{
//             ans++;
//         }
//         s.insert(root->val);
//         recursive(root->left);
//         recursive(root->right);
//         if(s.find(root->val)!=s.end()){
//             s.erase(s.find(root->val));
//         }
//         // s.erase(root->val);
//         return;
//     }
// };
// better way
class Solution {
public:
    int goodNodes(TreeNode* root) {
        int result = 0;
        dfs(root, root->val, result);
        return result;
    }
private:
    void dfs(TreeNode* root, int maxSoFar, int& result) {
        if(root == NULL) return;
        if(root->val >= maxSoFar) result++;
        maxSoFar = max(maxSoFar, root->val);
        dfs(root->left, maxSoFar, result);
        dfs(root->right, maxSoFar, result);
        return;
    }
};