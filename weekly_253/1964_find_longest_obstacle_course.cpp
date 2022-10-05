#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> dp(n);       
        map<int, int> m;
        dp[0] = 1;
        m[obstacles[0]]++;
        for(int i = 1; i <n;i++){
            // if(obstacles[i]>=obstacles[i-1]){
            //     dp[i] = dp[i-1] + 1;
            //     m[obstacles[i]] = dp[i];
            // }
            // else{
                auto it = m.lower_bound(obstacles[i]);
                if(it->first==obstacles[i]){
                    dp[i] = it->second + 1;
                    m[obstacles[i]] = dp[i];
                    continue;
                }
                if(it!=m.begin()){
                    it--;
                    if(it->first<=obstacles[i]){
                        dp[i] = it->second + 1;
                        m[obstacles[i]] = dp[i];
                        continue;
                    }
                }
                if(it==m.begin()){
                    dp[i] = 1;
                    m[obstacles[i]] = dp[i];
                }

            // }

        } 
        return dp;
    }
};
