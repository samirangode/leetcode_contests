#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        int val;
        ans.push_back(0);
        for(int j =1 ; j<=n;j++){
            val=0;
            for(int i = 0; i< 32; i++){
                if(j==0) break;
                val+=j&1;
                j = j>>1;
            }
            ans.push_back(val);
        }
        return ans;
    }
};
