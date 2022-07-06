#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        for(int i : nums){
            um[i]++;
        }
        int ans = 0;
        for(int i :nums){
            if(um.find(k-i)!=um.end()){
                if((k-i)==i){
                    if(um[i]<=1){
                        continue;
                    }
                }
                ans++;
                if(um[i]<=1){um.erase(i);}
                else{um[i]--;}
                if(um[k-i]<=1){um.erase(i);}
                else{um[k-i]--;}
            }
        }
        return ans;
    }
};
