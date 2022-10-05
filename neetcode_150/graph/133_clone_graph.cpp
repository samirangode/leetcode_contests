#include <bits/stdc++.h>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<int,Node*> visited;
        unordered_set<int> visited_set;
        Node* temp = dfs(node, visited);
        cout<<"final node"<<endl;
        // for(auto it : node->neighbors){
        //     cout<<it->val<<endl;
        // }
        dfs_explore(temp, visited_set);
        return temp;
    }
    Node* dfs(Node* node, unordered_map<int,Node*> &visited){
        cout<<node->val<<" Printing the visited nodes"<<endl;
        for(auto it : visited){
            cout<<it.first<<endl;
        }
        if(node->neighbors.empty()){
           return new Node(node->val); 
        }
        Node* childNode = new Node(node->val);
        visited.insert({node->val,childNode});
        for(auto it : node->neighbors){
            if(visited.find(it->val)==visited.end()){
                childNode->neighbors.push_back(dfs(it, visited));
            }else{
                childNode->neighbors.push_back(visited[it->val]);
            }
        }
        return childNode;
    }
    void dfs_explore(Node* node, unordered_set<int> &visited){
        cout<<node->val<<" Printing the visited nodes"<<endl;
        visited.insert(node->val);
        if(node->neighbors.empty()){
           return;
        }
        // Node* childNode = new Node(node->val);
        for(auto it : node->neighbors){
            if(visited.find(it->val)==visited.end()){
                dfs_explore(it, visited);
            }else{
                cout<<it->val<<endl;
            }
        }
        return;
    }
};