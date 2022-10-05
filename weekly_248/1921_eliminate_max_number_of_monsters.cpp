#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool compareTime(pair<int,int> p1, pair<int, int>p2){
        long long commonD = p1.second * p2.second;
        long long p1num = p1.first * p2.second;
        long long p2num = p2.first * p1.second;
        return (p1num<p2num);
    }
    
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        // vector<int>(n) time;
        vector<pair<int,int>> time(n);
        for(int i = 0; i < n; i++){
            int g = __gcd(speed[i], dist[i]);
            time[i].first = dist[i] / g;
            time[i].second = speed[i] / g;  
        }
        sort(time.begin(),time.end(), compareTime);
        int eliminated = 1;
        int timeElapsed = 0;
        for(int i=1 ; i<n;i++){
            timeElapsed++;
            if(compareTime({timeElapsed,1},time[i])){
                eliminated++;
            }
            else{
                return eliminated;
            }
        }
        return eliminated;

    }
};
