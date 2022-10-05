#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        // int n = words.size();
        // vector<string> new_vec;
        // vector<string> new_words = words; 
        // for(int i = 0; i< n; i++){
        //     sort(words[i].begin(),words[i].end());
        // }
        // int i = 0; 
        // while(i < n-1){
        //     if(words[i]== words[i+1]){
        //         i++;
        //     }
        //     else{
        //         new_vec.push_back(new_words[i]);
        //         i++;
        //     }
        // }
        // if(words[n-1]!=words[n-2]) 
        //     new_vec.push_back(new_words[n-1]);
        // return new_vec;
        int n = words.size();
        vector<string> new_vec;
        new_vec.push_back(words[0]);
        string temp1,temp2;
        temp1 = words[0]; sort(temp1.begin(),temp1.end()); 
        for(int i = 1; i<n;i++){
            temp2 = words[i]; sort(temp2.begin(),temp2.end());
            if(temp2!=temp1){
                new_vec.push_back(words[i]);
            }
            temp1 = temp2;
        }
        return new_vec;       
    }
};