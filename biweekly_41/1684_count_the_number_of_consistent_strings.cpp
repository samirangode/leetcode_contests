#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> us;
        for(char c : allowed){
            us.insert(c);
        }
        int ans = 0;
        int n = words.size();
        bool finished = true;
        for(int i = 0; i<n; i++){
            finished = true;
            for(char c : words[i]){
                if(us.find(c)==us.end()){
                    finished = false; 
                    break;
                }
                if(finished) ans++;
            }
        }      
        return ans;
    }
};
