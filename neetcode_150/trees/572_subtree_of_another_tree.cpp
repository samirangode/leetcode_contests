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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        stack<TreeNode*> s;
        
        TreeNode* curr = root;
        TreeNode* curr1 = root;
        TreeNode* curr2 = subRoot;
        bool rootfound = false;
        bool loopbroken = false;
        int i = 0;
        while(curr!=NULL || !s.empty()){
            while(curr!=NULL){
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top(); s.pop();
            cout<<curr->val<<"curr val"<<endl;
            cout<<curr2->val<<"curr2 val"<<endl;
            if(curr->val == curr2->val){
                i++;
                curr1 = curr; rootfound = true;
                stack<TreeNode*> s1;
                stack<TreeNode*> s2;
                loopbroken = false;
                while((curr1!=NULL || !s1.empty()) && (curr2!=NULL || !s2.empty())){
                    while(curr1!=NULL && curr2!=NULL){
                        s1.push(curr1); s2.push(curr2);
                        curr1 = curr1->left; curr2 = curr2->left;
                    }
                    if(curr1!=curr2){loopbroken = true; break;}
                    curr1 = s1.top(); s1.pop();
                    curr2 = s2.top(); s2.pop();
                    if(curr1->val != curr2->val){loopbroken=true; break;}
                    curr1 = curr1->right; curr2 = curr2->right;
                }
                if(curr1!=curr2){loopbroken=true; break;}
                // if(s1.size()!=s2.size()){loopbroken=true; break;}
                if(!loopbroken) return true;
            }
            curr2 = subRoot;
            curr = curr->right;
        }
        // cout<<i<<endl;
        return false;
    }
};