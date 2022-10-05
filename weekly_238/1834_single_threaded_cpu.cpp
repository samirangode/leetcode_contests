#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool compareTasks(pair<vector<int>&, int> p1, pair<vector<int>&, int> p2){
        vector<int> a = p1.first;
        vector<int> b = p2.first;
        if(a[1]<b[1]){
            return false;
        }
        else if (a[1]==b[1])
        {
            if(a[0]<=b[0]){
                return false;
            }
            else{
                return true;
            }
        }
        else{
            return true;
        }
        return true;
                
    }
    
    
    
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int time = 0;
        vector <int> ans;
        int n = tasks.size();
        int j = 0;
        priority_queue<pair<vector<int>, int>> pq;
        int temp_t = 0;
        while(j<n){
            while(time>=tasks[j][0] && j<n){
                pq.push({tasks[j],j});
                j++;
            }
            if(!pq.empty()){
                temp_t = pq.top().first[1];
                time+=temp_t;
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;        
    }
};
