#include <bits/stdc++.h>

using namespace std;
#define ll long long

class Solution {
public:
    const ll MOD = 1e9 + 7;

    int n;
    vector<vector<ll>> freq,mem;
    string target;

    int go(int w, int t){
        if(t>=target.size()) return 1;

        if(w>=n) return 0;

        ll &ans = mem[w][t];
        if(ans>-1) return ans;

        int cur = target[t] - 'a';

        return ans = (go(w+1,t)+ (freq[w][cur]*go(w+1,t+1))%MOD)%MOD;

    }
    
    
    int numWays(vector<string>& words, string _target) {
        target = _target;
        int i, j, m = words.size();
        n = words[0].size();
        freq.resize(n,vector<ll>(26,0));
        mem.resize(n+1,vector<ll>(target.size()+1,-1));

        // Build the frequency table
        // At every word index frequency of each character
        for(int i = 0; i <m; i++){
            for(int j=0; j<n; j++){
                freq[j][words[i][j]-'a']++;
            }
        }    
        return go(0,0);
    }
};
