#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(unordered_map<char,int>&um){
        int odd = 0;
        for(auto i : um){
            if(i.second%2!=0){
                if(i.second == 1){
                    if(odd>0){
                        return false;
                    }
                    else{
                        odd++;
                    }
                }
                
            }
        }
        return true;
    }
    long long wonderfulSubstrings(string word) {
        int n = word.length();     
        unordered_map<char, int> um;
        long long ans = 0;
        for(int k = 1; k<n;k++){
            um.clear();
            for(int j = 0; j<k; j++){
                um[word[j]]++;
            }
            bool test = check(um);
            if(test) ans++;
            for(int i = 1; i<=n-k;i++){
                um[word[i-1]]--;
                um[word[i+k-1]]++;
                bool test = check(um);
                if(test) ans++;
            }
        }
        return ans;
    }
};
