#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0;
        int power = 31;
        for(int i = 0; i<32; i++){
            if(n&1){
                ans+=1<<power;
            }
            power--;
            n=n>>1;
        }
        return ans;      
    }
};
