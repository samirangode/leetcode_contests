#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string reformatNumber(string number) {
        string cleaned = "";
        int n = number.length();
        for(int i = 0; i<n; i++){
            if(number[i]>='0' && number[i]<='9'){
                cleaned += number[i];
            }
        }
        int len = cleaned.length();
        string ans = "";
        if(len<=4){
            if(len==4){
                ans+=cleaned.substr(0,2);
                ans+=cleaned.substr(2,2);

            }
            if(len==3){
                ans+=cleaned;
            }
            if(len==2){
                ans+=cleaned;
            }
            return ans;
        }
        int m = 0;
        if(len%3 == 0){
            m = len/3;
            m = m-1;
            for(int i = 0; i<m;i++){
                ans += cleaned.substr(i*3,3);
            }
        }
        return ans;
    }
};