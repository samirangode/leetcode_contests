#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        // int zero_n = n-1;
        int sum =0; int weekly_sum = 0; int prev_monday = 0;
        int prev_day = 0;
        for(int i = 0; i < n; i++){
            if(i==0){
                weekly_sum+= 1; prev_monday =1;
                prev_day = 1;
            }
            else if(i%7 == 0){
                sum+=weekly_sum;
                weekly_sum = 0;
                weekly_sum += prev_monday +1 ;
                prev_monday++; 
                prev_day = prev_monday;
            }
            weekly_sum+=prev_day+1; prev_day++;
        }      
        return sum + weekly_sum;
    }
};
