#include <bits/stdc++.h>

using namespace std;

struct TrieNode{
    bool flag = false;
    unordered_map<char,TrieNode*> children;
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode* head = new TrieNode();
        for(string word : dictionary){
            TrieNode* temp = head;
            for(char c : word){
                if(temp->children.find(c)==temp->children.end()){
                    temp->children.insert({c, new TrieNode()});
                }
                temp = temp->children[c];
            }
            temp->flag = true;
        }
        stringstream ss(sentence);
        string word;
        string ans = "";
        while(ss>>word){
            if(head->children.find(word[0])==head->children.end()){
                ans+=word+" ";
                continue;
            }
            string temp_word = ""; int i = 0; TrieNode* temp = head;
            while((temp->children.find(word[i])!=temp->children.end()) && temp->flag==false){
                temp = temp->children[word[i]];
                temp_word+=word[i];
            }
            ans+=temp_word + " ";
        }
        ans.pop_back();
        return ans;
    }
};