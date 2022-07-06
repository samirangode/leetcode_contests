#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& arr) {
        int n = arr.size();
        int end_time = 0;
        int curr_start = 0, curr_cook = 0;
        long long  wait = 0;
        long long total_wait = 0;
        for(int i=0; i<n;i++){
            curr_start =  arr[i][0];
            curr_cook = arr[i][1];
            if(curr_start >= end_time){
                end_time = curr_start + curr_cook;
                total_wait +=curr_cook;
            }
            else{
                // wait+=end_time - curr_start;
                total_wait += end_time - curr_start + curr_cook;
                end_time = end_time + curr_cook;
            }
        }
        return double(total_wait) / double(n);      
    }
};
