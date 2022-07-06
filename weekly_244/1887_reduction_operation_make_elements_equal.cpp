#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int, int> m;
        for(int i : nums){
            m[i]++;
        }
        map<int, int>::reverse_iterator reverse_it;
        int operations = 0;
        int nextVal = 0;
        int n = m.size();
        int i = 0;
        for(reverse_it = m.rbegin(); reverse_it!=m.rend();reverse_it++){
            if(i<n){
                nextVal = operations + reverse_it->second;
                operations +=nextVal;
            }
            i++;
        }
        return operations;

    }
};
