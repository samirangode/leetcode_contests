#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    typedef long long ll;
    int mod = 1e9 + 7;
    ll power(ll x, ll y){
        ll res = 1;
        while(y>0){
            if(y & 1){
                res  = (res*x)%mod;
            }
            y>>=1; // y/2
            x = (x*x)%mod;
        }
        return res%mod;
    }
    
    int maxNiceDivisors(int primeFactors) {
        int n = primeFactors;
        ll ans = 1;
        if(n<=3) return n;
        ll n3 = n / 3, rem = n%3;
        if(rem==1) rem = 4 , --n3;
        else if(!rem){
            rem = 1;
        }
        return (power(3,n3)*rem)%mod;
    }
};