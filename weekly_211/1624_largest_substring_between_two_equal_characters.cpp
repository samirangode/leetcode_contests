#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.length();
        unordered_map<char,int> um;
        int max_len = -1;
        for(int i = 0 ; i < n; i++){
            if(um.find(s[i])!=um.end()){
                max_len = max(max_len,i - um[s[i]]-1);
            }else{
                um.insert({s[i],i});
            }
        }
        return max_len;      
    }
};
