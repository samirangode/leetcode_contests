#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> scores(n,0);
        int pointed= 0;
        int max_index = 0;
        long long max_score = INT_MIN;
        for(int i = 0; i< n; i++){
            pointed = edges[i];
            scores[pointed]+=i;
            if(scores[pointed]>max_score){
                max_index = pointed;
                max_score = scores[pointed];
            }
            else if(scores[pointed]==max_score && pointed<max_index){
                max_index = pointed;
            }
        }
        return max_index;

    }
};
