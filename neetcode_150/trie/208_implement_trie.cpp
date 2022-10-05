#include <bits/stdc++.h>

using namespace std;
struct TrieNode{
    bool flag;
    unordered_map<char, TrieNode*> children;
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        // children = new unordered_map<char, Trie*>()
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(char c : word){
            if(curr->children.find(c)==curr->children.end()){
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->flag = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(char c : word){
            if(curr->children.find(c)==curr->children.end()){
                return false;
            }
            curr = curr->children[c];
        }
        if(!curr->flag) false;
        return true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char c : prefix){
            if(curr->children.find(c)==curr->children.end()){
                return false;
            }
            curr = curr->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
