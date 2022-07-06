#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int counter = 0;
        int sum = 0;
        sort(cost.begin(), cost.end());
        int n = cost.size();
        for(int i = 0; i<n ;i++){
            counter++;
            if(counter==3){
                counter = 0;
                continue;
            }
            sum+=cost[i];
        }
        return sum;
        
    }
};