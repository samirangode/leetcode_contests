#include <bits/stdc++.h>

using namespace std;

struct cmp{
    bool operator()(pair<int, int> a, pair<int,int> b){
        double ad = (a.first +1)/(double)(a.second +1) - (a.first) / (double)(a.second+1);
        double bd  = (b.first +1)/(double)(b.second +1) - (b.first) / (double)(b.second+1);
        return ad < bd;
    }
};
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double acc = 0;
        priority_queue<pair<int, int>, vector<pair<int,int>>,cmp> que;
        for(vector<int> i : classes){
            que.push({i[0],i[1]});
        }
        while(extraStudents--){
            pair<int,int> cur = que.top();
            que.pop();
            que.push({cur.first+1, cur.second + 1});
        }
        while(!que.empty()){
            pair<int,int> curr= que.top(); que.pop();
            acc+= curr.first/(double)curr.second;
        }
        return acc/(double)classes.size();     
    }
};
