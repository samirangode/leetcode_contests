#include <bits/stdc++.h>

using namespace std;

// struct TrieNode{
//     bool flag = false;
//     unordered_map<char,TrieNode*> children;
// };

// class WordDictionary {
// public:
//     TrieNode* root;
//     WordDictionary() {
//         root = new TrieNode();
//     }
    
//     void addWord(string word) {
//         TrieNode* temp = root;
//         for(char c : word){
//             if(temp->children.find(c)==temp->children.end()){
//                 temp->children.insert({c,new TrieNode});
//             }
//             temp = temp->children[c];
//         }
//         temp->flag = true;
//     }
    
//     bool search(string word) {
//         int i = 0; bool ans = false;
//         dfs(word,0,root,ans);
//         return ans;
//     }
//     void dfs(string &word, int i,TrieNode* temp, bool &ans){
//         if(i==word.size()){ans = true; return;}
//         if(word[i]=='.'){
//             for(auto it : temp->children){
//                 dfs(word,i+1,it.second,ans);
//             }
//             return;
//         }
//         if(temp->children.find(word[i])!=temp->children.end()){
//                 temp = temp->children[word[i]];
//                 dfs(word,i+1,temp,ans);
//                 return;
//         }
//         return;
//     }
// };

class TrieNode{
public:
    TrieNode* children[26];
    bool isWord;
    
    TrieNode(){
        for(int i =0; i<26; i++){
            children[i]=NULL;
        }
        isWord = false;
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root; int n = word.size();
        int curr = 0;
        for(int i = 0; i<n; i++){
            curr = word[i] - 'a';
            if(node->children[curr]== NULL){
                node->children[curr]=new TrieNode();
            }
            node = node->children[curr];
        }
        node->isWord=true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        return searchInNode(word,0,node);
    }
private:
    TrieNode* root;

    bool searchInNode(string &word, int i, TrieNode* node){
        if(node == NULL) return false;
        if(i==word.size()) return node->isWord;

        if(word[i]!='.'){
            return searchInNode(word, i+1,node->children[word[i]-'a']);
        }
        for(int j = 0; j<26; j++){
            if(searchInNode(word,i+1,node->children[j])){
                return true;
            }
        }
        return false;
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
