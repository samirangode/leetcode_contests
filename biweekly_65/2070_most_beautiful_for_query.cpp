#include <bits/stdc++.h>

using namespace std;

//using upper_bound

// class Solution {
// public:
//     vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
//         sort(items.begin(), items.end());
//         // compute prefix max
//         int n = items.size();
//         for(int i = 0; i<n;i++){
//             if(i==0) continue;
//             items[i][1] = max(items[i][1], items[i-1][1]);
//         }
//         vector<int> ans;
//         for(auto &pricereq : queries){
//             int arr[2] = {pricereq, INT_MAX};
//             int ind = upper_bound(items.begin(),items.end(), arr) - items.begin();
//             ind--;
//             if(ind>0){
//                 ans.push_back(items[ind][1]);
//             }
//             else{
//                 ans.push_back(0);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> ans(queries.size(),0);
        sort(items.begin(), items.end());
        vector<pair<int,int>> vec;

        for(int i =0; i<queries.size();i++){
            vec.push_back({queries[i],i});
        }
        sort(vec.begin(), vec.end());
        int i = 0;
        int maxi = 0;
        int m = items.size();
        for(auto it: vec){
            int ind = it.second;
            int pricereq = it.first;
            while(ind<m&&items[i][0]<=pricereq){
                maxi = max(maxi, items[i][1]);
            }
            ans[ind] = maxi;
        }
        return ans;
        
    }
};
