#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int n = points.size();
        long long maxd = 0;
        for(int i = 1; i <n ;i ++){
            maxd = max(maxd,1ll*(points[i][0]- points[i-1][0]));
        }
        return maxd;      
    }
};
