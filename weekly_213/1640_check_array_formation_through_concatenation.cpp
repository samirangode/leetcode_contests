#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int n = arr.size();
        unordered_map<int,pair<bool,int>> um;
        int pieces_size = pieces.size();
        for(int i = 0; i<pieces_size;i++){
            int num = pieces[i].size();
            bool multiple = num > 1 ? true : false;
            for(int j = 0; j <num; j++){
                
                um.insert({pieces[i][j],{multiple,i}});
            }
        }
        for(int i = 0; i< n;){
            if(um.find(arr[i])==um.end()) return false;
            auto it = um[arr[i]];
            if(it.first){
                int j = 0, m = pieces[it.second].size();
                while(j<m && pieces[it.second][j]==arr[i]){
                    i++; j++;
                }
                if(j<m) return false;
                else continue;
            }
            i++;
        }
        return true; 
    }
};
