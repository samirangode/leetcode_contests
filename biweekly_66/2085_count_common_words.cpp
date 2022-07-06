#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> um;
        unordered_map<string, int> um2;
        for(string s : words1){
            um[s]++;
        }
        for(string s : words2){
            um2[s]++;
        }
        int count = 0;
        for(string s : words2){
            if(um.find(s)!=um.end() && um[s]==1 && um2[s]==1){
                count++;
            }
        }
        return count;        
    }
};