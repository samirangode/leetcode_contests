#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> um;
        vector<vector<string>> vec;
        int n = strs.size();
        string s = "";
        for(int i = 0; i<n; i++){
            s = strs[i];
            sort(s.begin(), s.end());
            if(um.find(s)==um.end()){
                vector<string> temp;
                um[s] = temp;
                um[s].push_back(strs[i]);
            }
            else{
                um[s].push_back(strs[i]);
            }
        }
        for(auto it : um){
            vec.push_back(it.second);
        }
        return vec;
    }
};