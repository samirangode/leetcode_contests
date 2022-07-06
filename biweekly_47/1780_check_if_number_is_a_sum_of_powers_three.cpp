#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkPowersOfThree(int n) {
        int rem = n%3;
        if(rem==2){
            return false;
        }
        int div = n;
        while(div!=0 || div!=1 || div!=2){
            div = div/3;
        }
        if(div==2) return false;
        return true;      
    }
};
