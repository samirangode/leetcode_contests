#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumBuckets(string street) {
        string s = street;
        int n = s.length();
        int  count = 0;
        for(int i = 0; i<n; i++){
            if(s[i]=='H'){
                if(i>0 && s[i-1]=='B'){
                    s[i] = 'C';
                    continue;
                }
                if(i<n-1 && (s[(i+1)%n] == '.')){
                    s[i] = 'C';
                    s[i+1] = 'B';
                    count ++;
                    continue;
                }
                if(i>0 && (s[(i-1)%n]=='.')){
                    s[i] = 'C';
                    s[i-1] = 'B';
                    count ++;
                    continue;
                }
                return -1;
            }
        }
        return count;        
    }
};