#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        // int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(n-2, vector<int>(n-2,0));
        int max_val = INT_MIN;
        for (int i = 0; i<n-2; i++ ){
            for(int j = 0; j <n-2; j++){
                for (int l = 0; l <3; l++){
                    for(int m = 0; m< 3; m++){
                       max_val = max(grid[i+l][j+m],max_val);
                       ans[i][j] = max_val;
                    }
                }
            }
        }
        return ans;
    }
};
