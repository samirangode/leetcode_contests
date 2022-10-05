#include <bits/stdc++.h>

using namespace std;

typedef pair<vector<int>&, int> pd;
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
    struct CustomCompare
{
    bool operator()(pair<vector<int>&, int> p1, pair<vector<int>&, int> p2)
    {
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
};
    
    
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int time = 1;
        vector <int> ans;
        int n = tasks.size();
        int j = 0;
        // priority_queue<pair<vector<int> &, int>, CustomCompare> pq;
        priority_queue<pd, vector<pd>, CustomCompare> pq;
        int temp_t = 0;
        // bool cpu_idle =true;
        while(j<n){
            // cout<<j<<" "<<time<<endl;
            while(j<n && time>=tasks[j][0]){
                // cout<<"here"<<endl;
                // pq.push({tasks[j],j});
                pq.push({tasks[j],j});
                j++;
                // cout<<j<<endl;
                // cout<<"here"<<endl;
                
            }
            // cout<<j<<endl;
            // cout<<pq.empty()<<endl;
            // cout<<"works"<<endl;
            cout<<pq.size()<<endl;
            if(!pq.empty()){
                // temp_t = pq.top().first[1];
                // cout<<"val"<<endl;
                auto val = pq.top();
                // cout<<"temp_t"<<endl;
                int temp_t = val.first[1];
                // cout<<temp_t<<endl;                
                time+=temp_t;
                ans.push_back(pq.top().second);
                pq.pop();
            }
            else{time++;}
        }
        cout<<"here"<<endl;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;        
    }
};

