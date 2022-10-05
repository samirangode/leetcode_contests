#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<int> target = times[targetFriend];
        sort(target.begin(),target.end());
        int myTime = target[0];
        int minChair = INT_MAX;
        int i = 0;
        int targetChair = INT_MAX;
        for(auto it : times){
            if(it[0]==myTime){
                targetChair = min(minChair, i);
                return targetChair;
            }
            if(it[1]<=myTime){
                minChair = min(minChair, i);
            }
            i++;
        }
    }
};
