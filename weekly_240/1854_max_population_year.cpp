#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        // map<int,int> start;
        int n = logs.size();
        int alive[2051];
        for(auto &l : logs){
            alive[l[0]]++;
            alive[l[1]]--;
        }
        int res = 1950;
        for(int i = 1950 ; i< 2050; i++){
            alive[i]+=alive[i-1];
            res = alive[i] > alive[res] ? i : res;
        }
        return res;
        
    }
};