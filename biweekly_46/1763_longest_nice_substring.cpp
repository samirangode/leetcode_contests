#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.length();
        int diff = 0; 
        // int x = 0;
        for(int i = 0; i<n; i++){
            
            // if(i == 0){x = s[i];}

            if(s[i]>='A' && s[i]<='Z'){
                diff = s[i] - 'A';
                s[i] = 'a' + diff;
            }
            // if(i!=0) x = x^s[i];
        }
    }
};