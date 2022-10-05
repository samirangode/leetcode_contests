#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n = s.length();
        int  count = 0, lastOne = -1;
        for(int i = 0; i < n ;i++){
            if(s[i]=='0') count ++;
            if(s[i]=='1' && count>0){
                if(lastOne>0 && lastOne==i-1){
                    count++;
                    lastOne = i;    
                }
            }
        }
        if(lastOne==-1) return 0;
        return count - n +lastOne;
    }
    
};
