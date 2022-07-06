#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size();
        vector<int> ans; ans.push_back(first);
        for(int i = 1; i<n+1; i++){
            ans.push_back(first ^ encoded[i]);
        }
        return ans;      
    }
};
