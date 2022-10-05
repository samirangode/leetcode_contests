#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkString(string s) {
        bool ansFlag = true;
        bool bHitFlag = false;
        for(char c : s){
            if(c == 'a' && bHitFlag){
                ansFlag = false;
            }
            if(c == 'b' && !bHitFlag){
                bHitFlag = true;
            }
        }

        return ansFlag;        
    }
};
