#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int checkSwaps(string s, string final){
        int n = s.length();
        int count = 0;
        for(int i = 0; i<n;i++){
            if(s[i]!=final[i]) count++;
        }
        return count/2;
    }
    
    int minSwaps(string s) {
        int n = s.length();
        int ones=0,zeros = 0;
        for(int i = 0; i < n; i++){
            if(s[i]=='0') zeros++;
            else ones++;
        }
        if(abs(ones-zeros)>1) return -1;
        if(ones == zeros){
            string s0,s1 = "";
            for(int i = 0; i<n;i++){
                s0+='0';s1+='1';
                s0+='1';s1+='0';
            }
            return min(checkSwaps(s,s0), checkSwaps(s,s1));
        }else{
            string final = "";
            if(ones>zeros){
                final="1";
                for(int i = 0; i<n-1;i++){
                    final+='0';
                    final+='1';
                }
            }
            else{
                final="0";
                for(int i = 0; i<n-1;i++){
                    final+='1';
                    final+='0';
                }
            }
            return checkSwaps(s,final);
        }
        return -1;
    }
};
