#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n,-1);
        vector<int> dist2(n,-2);
        int node = node1;
        int temp_dist = 0;
        while(edges[node]!=-1){
            dist1[node] = temp_dist;
            node = edges[node];
            temp_dist++;
        }
        node = node2; temp_dist = 0;
        while(edges[node]!=-1){
            dist2[node] = temp_dist;
            node = edges[node];
            temp_dist++;
        }
        int ans = 0; int min_dist = INT_MAX;
        temp_dist = 0;
        for(int i = 0; i < n; i++){
            temp_dist = max(dist1[i],dist2[i]);
            if(temp_dist<min_dist){
                ans = i;
                min_dist = temp_dist;
            }
        }
        return ans;

    }
};
