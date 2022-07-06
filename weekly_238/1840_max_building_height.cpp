#include <bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     int maxBuilding(int n, vector<vector<int>>& restrictions) {
//         vector<int> bh(n);
//         sort(restrictions.begin(),restrictions.end());
//         int j = 0;
//         for(int i = 1; i < n; i++){
//             bh[i] = bh[i-1]+1;
//             if(restrictions[j][0]==i+1){
//                 bh[i] = min(bh[i], restrictions[j][1]);
//                 j++;
//             }
//         }
//         int max_h = 0;
//         for(int i = n-2; i>0; i--){
//             bh[i] = min(bh[i+1] + 1, bh[i]);
//             max_h = max(max_h, bh[i]);
//         }      
//         return max_h;
//     }
// };
class Solution {
public:
    int pass(vector<vector<int>> &r){
        int res = 0;
        int n = r.size();
        int h,h1,h2;
        for(int i =0; i<n-1;i++){
            h1 = r[i][1]; h2 = r[i+1][1];
            h = h1 + abs(r[i+1][0] - r[i][0]);
            if(h>h2){
                h = h2 + (h-h2)/2;
            }
            res = max(res,h);
            r[i+1][1] = min(h,h2);
        }
        return res;
    } 
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.insert(restrictions.end(),{{1,0},{n,n-1}});
        sort(restrictions.begin(),restrictions.end());
        pass(restrictions); // passed by reference, changes r l to r
        reverse(restrictions.begin(),restrictions.end());
        //reuse pass this time r to l
        return pass(restrictions);
    }
};
