#include <bits/stdc++.h>

using namespace std;
// int ft[3001]
class Solution {
public:
    const int mod = 1e9 + 7;
    int modpow(int x, unsigned int y, int m){
        if(y == 0){
            return 1;
        }
        long p = modpow(x, y /2, m)%m;
        p = (p*p)%m;
        return y%2 ? (p*x) % m : p;
        
    }
    int makeStringSorted(string s) {
        long long ans = 0;
        unordered_map<int, long long> freq;
        for(char c :s){
            freq[c - 'a']+=1;
        }
        int l = s.size();
        vector<long long>fact(s.size(),1ll);
        for(int i = 1 ; i<=l;i++){
            fact[i] = (fact[i-1]*i)%mod;
        }
        for(char c : s){
            l--;
            long long t = 0, rev = 1;
            for(int i = 0; i< 26; i++){
                if(i< c - 'a'){
                    t+=freq[i];
                }
                //below is for the inverse
                rev = (rev*fact[freq[i]])%mod; 
            }
            ans+=(t*fact[l]%mod) * modpow(rev, mod - 2, mod);
            ans%=mod;
            freq[c-'a']--;

        }
        return ans; 

    }
};
