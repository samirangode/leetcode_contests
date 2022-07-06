#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long MX = 999999999999;
    bool dfs(string s, long long prev, int idx, int cnt){
        int n = s.size();
        if(idx == n)return cnt>1;

        long long num = 0;
        for(int i = idx; i<n; i++){
            num = num*10l + s[i] - '0';
            if(num>MX) break;       
            if(num==prev-1 || prev==-1){
                if(dfs(s,num, i +1, cnt+1)) return true;
            }
            if(num>prev && prev!=-1) break;
        }
        return false;
    }
    
    
    bool splitString(string s) {
        if(s.size()<=1) return false;
        return dfs(s,-1,0,0);
    }
};
