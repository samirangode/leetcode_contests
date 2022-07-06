#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countElements(vector<int>& nums) {
        map<int,int> m;
        for(int i : nums){
            m[i]++;
        }
        int ans = 0;
        auto it = m.begin();
        it++;
        int i = 1;
        int n = m.size();
        while(i<n-1){
            ans += it->second;
            it++;
            i++;
        }
        return ans;              
    }
};