#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        // queue<int> q;
        int n = tickets.size();
        // for(int i = 0; i< n; i++){
        //     q.push(tickets[i]);
        // }
        // int tick = tickets[k];
        int i = 0;
        int time = 0;
        while(tickets[k]>0){
            i= 0;
            if(tickets[k]==1){
                while(i<=k){
                    if(tickets[i]>0){
                    time++;
                    tickets[i]--;
                    }
                i++;    
                }
            break;
            }
            while(i<n){
                if(tickets[i]>0){
                    time++;
                    tickets[i]--;
                }
                i++;
            }
        }
        return time;
    }
};