#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long period = 0;
        for(int i =0 ;i<prices.size(); i++){
            if(i == 0){
                period++;
            }
            else{
                if(prices[i] + 1 == prices[i-1]){
                    continue;
                }
                else{
                    period++;
                }
            }
        }      
        return period;
    }
};