#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> um;
        for(string s: arr){
            um[s]++;
        }
        int i = 0;
        for(auto it : um){
            if(it.second==1){
                i++;
                if(i==k){
                    return it.first;
                }
            }
        }
        return "";
    }
};