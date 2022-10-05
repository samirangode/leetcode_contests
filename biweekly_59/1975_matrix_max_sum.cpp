#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        bool odd = false;
        long long sum = 0;
        int abs_min = INT_MAX;
        int num = 0;
        for(auto row : matrix){
            for(auto i : row){
                if(i<0){
                    odd = !odd;
                }
                num = abs(i);
                sum+=num;
                abs_min = min(num,abs_min);

            }
        }
        if(odd){
            sum-=abs_min;
        }
        return sum;
        
    }
};