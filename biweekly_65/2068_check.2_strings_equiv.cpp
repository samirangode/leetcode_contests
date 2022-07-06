#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        unordered_map<char, int> um1;
        unordered_map<char, int> um2;
        int n = word1.length();

        for(int i = 0; i< n; i++){
            um1[word1[i]]++;
            um2[word2[i]]++;
        }
        for(pair<char,int> p : um1){
            if(um2.find(p.first)==um2.end()){
                return false;
            }
            if(abs(p.second-um2[p.first])>3){
                return false;
            }
        }
        for(pair<char,int> p : um2){
            if(um2.find(p.first)==um1.end()){
                return false;
            }
            if(abs(p.second-um1[p.first])>3){
                return false;
            }
        }
        return true;    
    }
};