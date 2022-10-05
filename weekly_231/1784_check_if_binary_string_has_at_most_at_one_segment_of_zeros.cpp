#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.length();
        bool ans = true;
        int last_index = -1;
        for(int i = 0; i<n; i++){
            if(s[i]=='1'){
                if(last_index==-1){
                    last_index = i;
                    continue;
                }
                if(last_index ==i-1){
                    last_index = i;
                    continue;
                }
                if(last_index!=(i-1)){
                    ans = false;
                }
            }
        }
        return ans;      
    }
};
