#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    #define f first;
    #define s second;
    vector<int> v{0,0};
    double ans = 0;
    
    double dist(int x1, int y1, int x2, int y2){
        return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    }

    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        queue<pair<int,int>> q;
        int n = towers.size();
        for(int i = 0; i< n; i++){
            q.push({towers[i][0], towers[i][1]});
        }
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();

            double temp = 0;
            for(int i = 0; i< n; i++){
                double temp_dist = dist(towers[i][0], towers[i][1], p.first , p.second);
                if(temp_dist> radius)
                    continue;
                temp+=floor(1/(1 + temp_dist));
            }

            if(temp>ans){
                ans = temp;
                v = {p.f, p.s};
                q.push({p.first-1, p.second-1});
                q.push({p.first+1, p.second+1});
                q.push({p.first-1, p.second+1});
                q.push({p.first+1, p.second-1});
                q.push({p.first, p.second-1});
                q.push({p.first, p.second+1});
                q.push({p.first-1, p.second});
                q.push({p.first+1, p.second});

            }
            else if(temp == ans){
                if(v[0] > p.f || (v[0] == p.f and v[1] > p.s))
                    v = {p.f, p.s};
            }
            else continue;
        }
        return v;
    }
};
