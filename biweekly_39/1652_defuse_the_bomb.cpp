#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        if(k==0){
            for(int i = 0; i< n; i++){
                code[i] = 0;
            }
        }
        vector<int> ans(n,0);
        if(k>0){
            int suffix_sum = 0;
            for(int i= 0; i< k; i++){
                suffix_sum+=code[(1+i)%n];
            }   
            for(int i = 0; i<n;i++){
                ans[i] = suffix_sum;
                suffix_sum -= code[(i+1)%n];
                suffix_sum  = suffix_sum + code[(i+1+k)%n];
            }
        }
        if(k<0){
            int suffix_sum = 0;
            for(int i=0; i<k; i++){
                suffix_sum-=code[(-1-i)%n];
            }
            for(int i = 0; i<n;i++){
                ans[i] = suffix_sum;
                suffix_sum -=code[(i-1)%n];
                suffix_sum +=code[(i-1-k)%n];
            }
        }
        return ans;     
    }
};

