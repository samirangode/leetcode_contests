#include <bits/stdc++.h>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        string ans;
        if(root==NULL){
            ans.append("-1001");
            return ans;
        }
        q.push(root);
        ans.append(","+to_string(root->val));
        int size = 0;
        while(!q.empty()){
            size = q.size();
            for(int i = 0; i< size; i++){
                TreeNode* t = q.front();
                q.pop();
                if(t->left){
                    q.push(t->left); ans.append("," + to_string(t->left->val));
                }else{
                    ans.append(","+ to_string(-1001));
                }
                if(t->right){
                    q.push(t->right); ans.append("," + to_string(t->right->val));
                    
                }else{
                    ans.append(","+ to_string(-1001));
                }
            }
        }     
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==5 && data == "-1001"){
            return NULL;
        }
        queue<TreeNode*> q;
        
        int comma_pos = data.find(',');
        TreeNode* root = new TreeNode(stoi(data.substr(0,comma_pos)));
        q.push(root);
        int i =1;
        int comma_pos_prev = comma_pos;
        while(!q.empty()){
            comma_pos = data.find(',',comma_pos_prev+1);
            int left_val = stoi(data.substr(comma_pos_prev+1,comma_pos-comma_pos_prev-1));
            comma_pos_prev = comma_pos;
            comma_pos = data.find(',',comma_pos_prev+1);
            int right_val = stoi(data.substr(comma_pos_prev+1,comma_pos-comma_pos_prev-1));
            comma_pos_prev = comma_pos;
            TreeNode* t = q.front();
            
        }
        
    }
};

