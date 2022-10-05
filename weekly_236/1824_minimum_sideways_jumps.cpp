
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int f(int lane, int index, vector<int> &obstacles,
    vector<vector<int>> &dp){
        if(index == 0){
            if(lane == 1) return dp[lane][index]=0;
            else return dp[lane][index]=1;
        }
        if((obstacles[index]-1) == lane){
            return dp[lane][index]=INT_MAX;
        }
        // int a,b;
        if(obstacles[index-1]!=(lane+1)){
            if(dp[lane][index-1]!=-1){
                return dp[lane][index-1];
            }
            return dp[lane][index-1]=f(lane,index-1,obstacles,dp);
            // return f(lane,index-1,obstacles);

        }
        // return min(f((lane+1)%3,index,obstacles),
        //     f((lane+2)%3,index,obstacles))+1;
        int a,b;
        if(dp[(lane+1)%3][index]!=-1){
            a = dp[(lane+1)%3][index];
        }else{
            a = f((lane+1)%3,index,obstacles,dp);
        }

        if(dp[(lane+2)%3][index]!=-1){
            b = dp[(lane+2)%3][index];
        }else{
            b = f((lane+2)%3,index,obstacles,dp);
        }
        return min(a,b)+1;
        
    }
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size()-1;
        vector<vector<int>> dp(3,vector<int>(n+1,-1));
        return min(f(0,n,obstacles,dp),min(f(1,n, obstacles,dp),f(2,n, obstacles,dp)));        
    }
};