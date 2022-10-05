#include <bits/stdc++.h>

using namespace std;
bool sortcol(const vector<int> &v1, const vector<int> &v2){
        return v1[1]>v2[1];
    }
class Solution {
public:
    
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        int m = nums.size();
        for(int i=0; i<n; i++){
            queries[i].push_back(i);
        }
        vector<vector<string>> vec(m,vector<string>(2,""));
        for(int i = 0; i< m; i++){
            vec[i][0] = nums[i];
            vec[i][1] = to_string(i);
        }
        sort(queries.begin(),queries.end(),sortcol);
        vector<int> ans(n,0);
        for(int i = 0; i< n;i++){
            int curr_len = nums[0].size();
            for(int j = 0; j< m; j++){
                vec[j][0] = vec[j][0].substr(curr_len - queries[i][1],queries[i][1]);
                // cout<<nums[j]<<endl;
            }
            sort(vec.begin(),vec.end());
            // cout<<"......"<<endl;
            // for(int k = 0; k< m; k++){
            //     cout<<nums[k]<<endl;
            // }
            // cout<<"......"<<endl;
            cout<<queries[i][0]+1<<endl;
            ans[queries[i][2]] = stoi(vec[queries[i][0]-1][1]);
        }
        return ans;

    }
};
