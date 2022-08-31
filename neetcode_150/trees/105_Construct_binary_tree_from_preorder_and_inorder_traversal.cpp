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

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootidx = 0;
        TreeNode* root;
        root = build(rootidx, 0, preorder.size()-1,preorder,inorder);
        return root;

    }
    TreeNode* build(int &rootidx, int lef, int rig,vector<int>& preorder, vector<int>& inorder){
        if(lef>rig) return NULL;
        int index = lef;
        while(preorder[rootidx]!=inorder[index]&& index<rig){
            index++;
        }
        rootidx++;
        TreeNode* newNode = new TreeNode(preorder[rootidx]);
        newNode->left = build(rootidx, lef, index-1, preorder, inorder);
        newNode->right = build(rootidx, index+1, rig, preorder, inorder);
        return newNode;

    }
};

