#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int left_sum = 0;
        int left_qs = 0;
        int right_sum = 0;
        int right_qs = 0;
        for(int i = 0; i <n; i++){
            if(i<n/2){
                if(num[i]=='?'){
                    left_qs++;
                }
                else{
                    left_sum+= num[i] - '0';
                }
            }
            else{
                if(num[i]=='?'){
                    right_qs++;
                }
                else{
                    right_sum += num[i] - '0';
                }

            }
        }        
    
        int totalqs = left_qs + right_qs;
        if(totalqs%2 > 0) return true;
        
         
    
    }
};
