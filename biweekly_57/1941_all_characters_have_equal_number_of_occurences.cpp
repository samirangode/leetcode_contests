#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int n = s.length();
        unordered_map<char,int> um;
        for(char c: s){
            um[c]++;
        }
        int check = um[s[0]];
        for(auto it : um){
            if(it.second != check){
                return false;
            }
        }
        return true;
    }
};
