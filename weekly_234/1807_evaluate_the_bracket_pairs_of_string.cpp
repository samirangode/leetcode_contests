#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> um;
        int n = knowledge.size();
        for(int i = 0; i<n;i++){
            // um.insert({knowledge[i][0],knowledge[i][1]});
            um[knowledge[i][0]] = knowledge[i][1];
        }
        int i = 0;
        int len = s.length();
        string ans = "";
        string key = "";
        while(i<len){
            key = "";
            if(s[i]=='('){
                i++;
                while(s[i]!=')'){
                    key +=s[i];
                    i++;
                }
                if(um.find(key) != um.end()){
                    ans+=um[key];
                }
                else{
                    ans+="?";
                }
                i++;
                continue;
            }
            ans+=s[i];
            i++;
        }
        return ans;
        
    }
};
