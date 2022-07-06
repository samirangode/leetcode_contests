#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int secondHighest(string s) {
        int n = s.length();
        int maxi = INT_MIN;
        int maxi_2 = INT_MIN;
        for(int i = 0; i< n; i++){
            if(s[i]<='9' && s[i]>='0'){
                int a = s[i] - '0';
                if(a>maxi){
                    maxi_2 = maxi;
                    maxi = a;
                }   
            }
        }
        if(maxi_2!=INT_MIN && maxi_2!=maxi) return maxi_2;
        return -1;       
    }
};
