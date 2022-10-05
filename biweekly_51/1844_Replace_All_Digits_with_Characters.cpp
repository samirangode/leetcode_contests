
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string replaceDigits(string s) {
        int n = s.length();
        for(int i = 0; i <n; i++){
            if(i%2==0) continue;
            int diff= s[i] - '0';
            char c = s[i-1] + diff;
            s[i] = c;
        }
        return s;       
    }
};