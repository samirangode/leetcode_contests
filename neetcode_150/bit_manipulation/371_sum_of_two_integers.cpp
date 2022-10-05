#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        int x = abs(a), y = abs(b);
        if(x<y){
            return getSum(b,a);
        }
        int sign = a > 0 ? 1:-1;
        if(a*b >= 0){
            // SUM
            while(y!=0){
                int answer = x^y;
                int carry = (x&y)<<1;
                x = answer;
                y = carry;
            }
        }else{
            // Difference
            while(y!=0){
                int answer = x^y;
                int borrow = ((~x)&y)<<1;
                x = answer; 
                y = borrow;
            }
        }
        return x*sign;
    }
};