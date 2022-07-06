#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n = groups.size();
        int m = nums.size();

        int i = 0,j = 0;
        while(i<m){
            if(nums[i]==groups[j][0]){
                int t = i;
                bool finished = true;
                for(int g : groups[j]){
                    if(nums[t] == g) t++;
                    else finished = false;
                }
                if(finished){ j++; i=t;}
                else i++;
            }
            else i++;

            if(j==n) return true;

        }
        if(j==n) return true;
        
        return false;      
    }
};
