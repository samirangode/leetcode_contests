#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0; int dist = INT_MAX; int min_dist = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            if(points[i][0] == x || points[i][1]==y){
                dist = abs(points[i][0] - x) + abs(points[i][1]-y);
                if(dist<min_dist){
                    ans = i;
                    min_dist = dist;
                }
            }   
        }
        if(min_dist == INT_MAX){
            return -1;
        }
        return ans;      
    }
};