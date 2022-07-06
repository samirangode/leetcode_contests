#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> ansTill(n);
        ansTill[0] = 0;
        int prevP = -1;
        vector<int> validP(n);
        validP[0] = 0;
        if(s[0]=='|'){
            prevP = 0;
        }
        int stars = 0;
        for(int i = 1; i<n;i++){
            if(s[i]=='*' && prevP>=0){
                stars++;
                ansTill[i] = ansTill[i-1];
            }
            if(s[i]=='|'){
                if(prevP<0){
                    prevP = i;
                    continue;
                }
                else{
                    ansTill[i] = ansTill[i-1] + stars;
                    stars = 0;
                    if((i-prevP)>1){
                        validP[i]++;
                    }
                    prevP = i;
                }
            }
        }
        vector<int> ans;
        for(vector<int> q : queries){
            int tempAns = ansTill[q[1]]-ansTill[q[0]];
            int tempValidP = validP[q[1]] - validP[q[0]];
            if(tempValidP>0) ans.push_back(tempAns);
            else{
                ans.push_back(0);
            }
        }
        return ans;        
    }
};