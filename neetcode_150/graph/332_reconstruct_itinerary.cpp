#include <bits/stdc++.h>

using namespace std;

class myComparator{
    public:
        int operator() (string s1, string s2){
            return s1>s2;
        }
};
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // priority_queue<string,vector<string>,myComparator> pq;
        unordered_map<string,priority_queue<string,vector<string>,myComparator>> um;
        int n = tickets.size();
        for(int i=0; i<n; i++){
            // cout<<tickets[i][0]<<" "<<tickets[i][1]<<endl;
            um[tickets[i][0]].push(tickets[i][1]);
        }
        vector<string> ans;
        vector<string> temp_ans;
        temp_ans.push_back("JFK");
        string curr = "JFK";
        while(curr!=""){
            cout<<curr<<endl;
            if(!um[curr].empty()){
               string curr2 = um[curr].top();
                um[curr].pop();
                curr = curr2;
                ans.push_back(curr);
            }
            else{
                curr = "";
            }
        }
        return ans;
    }
};