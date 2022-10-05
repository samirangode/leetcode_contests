#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int> s;
        for(int i : nums){
            s.insert(i);
        }
        int n = nums.size();
        int m = s.size();
        vector<int> vec(m);
        for(auto& i : s ){
            vec.push_back(i);
        }
        int maxi = INT_MIN;
        int cont_max = 0;
        int num_i = 0;
        int num = 0;
        for(int j = 0; j <m-1; j++){
            cont_max = vec[j] + n -1;
            if(cont_max>vec[m-1]){
                
            }
            auto it = lower_bound(vec.begin(), vec.end(), cont_max);
            
            num_i = it - vec.begin();
        }
                
    }
};