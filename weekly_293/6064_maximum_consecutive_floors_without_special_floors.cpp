#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        // int n = top - bottom+1;
        // int floors[n];
        // int m = special.size();
        // unordered_set<int> us;
        // for(int i = 0; i < m; i++){
        //     // floors[special[i]-bottom] = -1;
        //     us.insert(special[i] - bottom);
        // }
        // int prev = 0; int maxi = 0;
        // for(int i = 0; i< n; i++){
        //     if(us.find(i)!=us.end()) prev = 0;
        //     else{
        //         // floors[i] = prev+1;
        //         prev = prev+1;
        //         maxi = max(maxi,prev);
        //     } 
        // }
        // return maxi;
        sort(special.begin(),special.end());
        int maxi = special[0] - bottom;
        int m = special.size();
        for(int i = 1; i< m; i++ ){
            maxi = max(maxi, special[i] - special[i-1]);
        }
        maxi = max(maxi, top - special[m-1]);
        return maxi;
    }
};
