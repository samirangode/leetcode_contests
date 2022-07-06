#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int concatenatedBinary(int n) {
        int mod = 1e9 + 7;
        long result = 0;
        int length = 0;
        for(int i = 1; i<=n; i++){
            // length of the new number i
            // will only increase if the new number is
            // power of 2
            if((i & (i-1)) == 0){
                length++;
            }
            // we will left shit the previous result by
            // length of the number to add it
            // We'll or the new number to add it
            result = ((result<<length)|i) % mod;
        }
        return result;        
    }
};