#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(int mid, vector<int> &dist, double hour){
        double time = 0;
        int n = dist.size();
        for(int i = 0 ; i<n-1;i++){
            time+= ceil( ((double)  dist[i] ) / mid);
        }
        time+= ((double)  dist[n-1] ) / mid;
        return hour>=time;
    }
    
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        int minDist = INT_MAX;
        int maxDist = INT_MIN;
        for(int i = 0; i <n;i++){
            if(dist[i]<minDist){
                minDist = dist[i];
            }
            if(dist[i]>maxDist){
                maxDist = dist[i];
            }
        }
        int low = 0;
        int high = (maxDist / int(hour/(2*n))) + 1;
        int mid = 0;
        bool flag = false;
        while(low<=high){
            mid = low + (high-low)/2 ;
            if(check(mid,dist,hour)){
                high = mid;
                flag = true;
            }
            else{
                low = mid+1;
            }

        }
        if(flag){
            return high;
        }
        else{
            return -1;
        }

    }
};
