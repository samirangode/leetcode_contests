#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkZeroOnes(string s) {
        int ones = 0;
        int zeros = 0;
        int n= s.length();
        int maxOne = INT_MIN;
        int maxZero = INT_MIN;
        for(int i = 0; i<n;i++){
            if(s[i]=='1'){
                ones++;
                zeros = 0;
            }
            else{
                zeros++;
                ones =0;
            }
            maxOne = max(maxOne, ones);
            maxZero = max(maxZero, zeros);
            return max(maxOne, maxZero);
        }           
    }
};