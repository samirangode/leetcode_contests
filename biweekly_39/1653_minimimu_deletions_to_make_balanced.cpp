#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> a(n+2,0);
        vector<int> b(n+2,0);
        for(int i = 1; i<=n; i++){
            if(s[i-1]=='b'){
                a[i] = a[i-1]+1;
            }
        }
        for(int i = n; i>=1; i--){
            if(s[i-1]=='a'){
                b[i]+=b[i+1];
            }
        }
        int min_deletions = INT_MAX;
        for(int i =1;i<=n;i++){
            min_deletions = min(min_deletions, a[i]+b[i+1]);
        }
        return min_deletions;      
    }
};