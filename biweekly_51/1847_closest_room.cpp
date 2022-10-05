#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        const int q =  int(queries.size());
        vector<int> res(q,-1);

        vector<int> qid(q,0);
        iota(qid.begin(),qid.end(),0);
        sort(qid.begin(),qid.end(),[&](const int &l, const int &r){return queries[l][1]>queries[r][1];});
        
        sort(rooms.begin(),rooms.end(), )
        set<int> room_ids = {};
        
        for(int i : qid){
            while(!rooms.empty() &&rooms.back()[1]>queries[i][1]){

            }
        }
    }
};
