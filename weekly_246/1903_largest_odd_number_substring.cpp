#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int dig = 0;
        for(int i=n-1; i>=0;i-- ){
            dig = num[i] - '0';
            if((dig%2)!=0){
                return num.substr(0,i);
            }
        }
        return "";        
    }
};
