#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        int ans = 0; int mul = 0;
        unordered_map<int,int> um;
        int n = deliciousness.size();
        for(int i = 0; i< n; i++){
            um[deliciousness[i]]++;
        }
        vector<int> arr;
        for(int i = 0; i<=21;i++){
            arr.push_back(pow(2,i));
        }
        int m = 1e9+7;
        for(auto i : um){
            for(auto j : arr){
                if((j - i.first)>=0){
                    if(um.find(j-i.first) != um.end()){
                        if(j - i.first != i.first){
                            mul = (um[j-i.first]%m * i.second%m)%m; 
                        }
                        else{
                            mul = ((i.second/2)%m * (i.second-1)%m)%m;
                        }                   
                        ans = (ans%m + mul%m)%m;
                    }

                }
            }
        }      
        return ans;
    }
};