#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long modPow(long long a, long long b, int mod = 1000000007){
        if(b == 0){
            return 1;
        }
        long long x = modPow(a, b/2, mod);
        if(b%2 == 0){
            return (x*x)%mod; 
        }
        else{
            return (a%mod *x *x)%mod;
        }
    }
    int countGoodNumbers(long long n) {
        int mod = 1000000007;
        return (modPow(5,(n+1)/2) * modPow(4, n/2))%mod;
    }
};