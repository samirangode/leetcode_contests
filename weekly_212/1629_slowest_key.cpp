#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        priority_queue<pair<int,char>> pq;
        int n = keysPressed.length();
        int time = 0;
        for(int i = 0; i<n; i++){
            if(i==0) time = releaseTimes[i];
            else{
                time = releaseTimes[i] - releaseTimes[i-1];
            }
            pq.push({time,keysPressed[i]});
        }
        int max_time = -1;
        char max_c;
        time = -2;
        while(time<=max_time){
            auto it = pq.top();
            time = it.first;
            char c = it.second;
            if(time>=max_time){
                if(time==max_time) max_c = max(max_c,c);
                max_time = time;
            }

        }      
        return max_c;
    }
};
