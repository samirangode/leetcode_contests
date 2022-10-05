#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char> um;
        int n = key.size();
        int i = 0;
        int j = 0;
        while(j<26 && i<n){
            if(key[i]>='a'&& key[i]<='z'){
                if(um.find(key[i])==um.end()){
                    um.insert({key[i],char('a'+j)});
                    j++;
                }
            }
            i++;
        }
        string ans = "";
        for(char c: message){
            if(c==' '){
                ans+=' ';
            }
            else{
                ans+=um[c];
            }
        }
        return ans;      
    }
};
