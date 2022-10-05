#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int last_val = 1;
        int n = arr.size();
        for(int i = 1; i< n;i++){
            if(arr[i]>last_val){
                last_val++;
            }
            else{
                last_val = arr[i];
            }
        }    
        return last_val;    
    }
};