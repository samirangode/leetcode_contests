#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string maxValue(string n, int x) {
        int len = n.length();
        string final = "";
        string t = to_string(x);
        char x_char = t[0];
        if(n[0]!='-'){
            for(int i = 0; i<len;i++){
                if(x_char>n[i]){
                    t = n.substr(0,i) + x_char + n.substr(i);
                }
            }
        }
        else{
            for(int i = 1; i<len;i++){
                if(x_char>n[i]){
                    t = n.substr(1,i-1) + x_char + n.substr(i);
                }
            }
        }
        return t;
    }
};
