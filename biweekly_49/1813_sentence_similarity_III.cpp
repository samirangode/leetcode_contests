#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkString(vector<string> first, vector<string> second){
        int prefix = -1, suffix = -1;
        int n1 = first.size(), n2 = second.size();
        for(int i = 0; i<n2; i++){
            if(first[i] != second[i]) 
            {   prefix = i;
                break;
            }
        }
        if(prefix == -1) prefix = n2;
        for(int i = 0; i < n2; i++){
            if(first[n1 -1 - i] != second [n2 -1 - i]){
                suffix = i;
                break;
            }
        }
        if(suffix == -1) suffix = n2;
        if((prefix + suffix) == n2){
            return true;
        }
        return false;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> v1;
        vector<string> v2 ;
        stringstream one(sentence1);
        stringstream two(sentence2);
        string word;
        while(one >> word){
            v1.push_back(word);
        }
        while(two >> word){
            v2.push_back(word);
        }
        // int prefix = 0, suffix = 0;
        bool ans;
        if(v1.size()>=v2.size()){
            ans = checkString(v1,v2);
        }else{
            ans = checkString(v2,v1);
        }
        return ans;

    }
};
