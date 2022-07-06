#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        int mod = 1e9 + 7;
        map<int, int> buy;
        map<int, int> sell;
        long long backlog = 0;
        // 0 buy order
        //1 sell order
        int n = orders.size();
        //[price, amound, order_type]
        for(int i = 0; i< n; i++){
            
            if(orders[i][2] == 0){
                // buy order
                auto it = sell.begin();
                if(it==sell.end() || it->first > orders[i][0]){
                    backlog+= orders[i][1];
                    buy.insert({orders[i][0],orders[i][1]});
                }
                else{
                    if(it->first<=orders[i][0]){
                        if(orders[i][1]>=it->second){
                            orders[i][1]-= it->second;
                            it->second = 0;
                            sell.erase(it);
                            if(orders[i][0]==0) continue;
                            backlog-=it->second;
                        }
                        else{
                            it->second-=orders[i][1];
                            backlog-=orders[i][1];
                            orders[i][1]= 0;
                        }
                        if(orders[i][1]>0){
                            buy.insert({orders[i][0],orders[i][1]});
                            backlog+=orders[i][1];
                        }
                    }
                }
            }
            if(orders[i][2]==1){
                //sell
                if(buy.size()==0){
                    sell.insert({orders[i][0],orders[i][1]});
                    backlog+=orders[i][1];
                }
                else{
                    auto it = buy.end();
                    it--;
                    if(orders[i][0]<=it->first){
                        if(orders[i][1]>=it->second){
                            orders[i][1]-=it->second;
                            backlog-=it->second;
                            it->second = 0;
                            buy.erase(it);
                        }
                        else{
                            it->second -=orders[i][1];
                            orders[i][1] = 0;
                            backlog -=orders[i][1];
                        }
                        if(orders[i][1]>0){
                            sell.insert({orders[i][0],orders[i][1]});
                            backlog+=orders[i][1];
                        }
                    }
                }
            }
        }     
        return backlog % mod;
    }
};