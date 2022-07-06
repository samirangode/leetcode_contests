#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix.size();
        int l = 0;
        priority_queue<int> ans;
        int val;
        for(int i =0; i< m; i++){
            for(int j = 0; j < n; j++){
                if(i==0 && j==0){
                    val = matrix[i][j];
                    ans.push(val);
                    continue;
                }
                // if(l==k) return val;
                val = val ^ matrix[i][j];
                ans.push(val);
            }
        }      
        while(!ans.empty()){
            l++;
            if(l==k) return ans.top();
            ans.pop();
        }
        return 0;
    }
};
