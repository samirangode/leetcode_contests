#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int prev_x = stockPrices[0][0];
        int prev_y = stockPrices[0][1];
        int n = stockPrices.size(); bool new_line = true;
        int slope_num, slope_den,gcd_val;
        int prev_slope_den, prev_slope_num;
        int num_lines = 0;
        for(int i = 0; i< n; i++){
            slope_den = stockPrices[i][0] - prev_x;
            slope_num = stockPrices[i][1] - prev_y;
            gcd_val = __gcd(slope_num,slope_den);
            slope_den = slope_den / gcd_val;
            slope_num = slope_num / gcd_val;
            if(!new_line){
                if(prev_slope_den == slope_den && prev_slope_num == slope_num){
                    continue;
                }
                else{
                    num_lines++;
                    new_line = true;
                }                
            }
            if(new_line){
                prev_slope_den = slope_den;
                prev_slope_num = slope_num;
                new_line = false;
            }
            prev_x = stockPrices[i][0];
            prev_y = stockPrices[i][1];
        }

    }
};
