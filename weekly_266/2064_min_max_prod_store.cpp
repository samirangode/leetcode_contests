#include <bits/stdc++.h>

using namespace std; 

class Solution {
public:
    bool checkMax(int mid, vector<int> quantities, int n){
        int req = 0;
        if(mid==0){
            return false;
        }
        int m = quantities.size();
        for(int i = 0; i < m; i++){
            req += quantities[i]/mid;
            if(quantities[i]%mid != 0 ){
                req+=1;
            }
        }
        if(req<=n){
            return true;
        }
        else{
            return false;
        }
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 0;
        int high = 0;
        int t = quantities.size();
        for(int i = 0;i<t; i++){
            if(quantities[i]>high){
                high = quantities[i];
            }
        }
        int mid = 0;
        int ans = high;
        while(low<=high){
            mid = low + (high - low)/2;
            if(checkMax(mid, quantities, n)){
                ans = mid;
                high = mid -1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};