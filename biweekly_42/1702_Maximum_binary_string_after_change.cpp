#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string f(string s, int i){
        if(i == s.size()){
            return s;
        }
        if(i > 0){
            if(s[i] == '0'){
                if(s[i-1]=='0'){
                    s[i-1] = '1';
                    string convert_0 = f(s,i+1);
                    s[i] = '0';
                    string no_convert = f(s, i+1);
                    return max(no_convert, convert_0);
                }
                if(s[i-1]=='1'){
                    s[i-1] = '0'; s[i] = '1';
                    string convert_1 = f(s, i+1);
                    s[i-1] = '1'; s[i] = '0';
                    string no_convert = f(s,i+1);
                    return max(no_convert, convert_1);
                }
            }
        }
        return s;
    }
    
    
    string maximumBinaryString(string binary) {
        // send with i = 1
        return f(binary, 1);
    }
};
