#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char,vector<int>> um;
        int n = s.length();
        for(int i =0; i<n; i++){
            um[s[i]].push_back(i);
        }
        
        
    }
};