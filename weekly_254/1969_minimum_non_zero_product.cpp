
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int modPow(long long x, long long y, int m){
        if(y==0){
            return 1;
        }
        long long p = modPow(x,y/2,m);
        p = (p*p)%m;
        return y%2 ? (p*(x%m))%m : p;
    }
    
    
    int minNonZeroProduct(int p) {
        long long k = pow(2,p-1) - 1;
        int i = 0;
        long long product = 1;
        long long last_num = pow(10,9)+7;
        product = (pow(2,p)-1);
        product%=last_num;
        long long rep_val = product - 1%last_num;
        while(i<k){
            product*=rep_val;
            product%=last_num;
            i++;
        }
        return (int)product;
    }
};