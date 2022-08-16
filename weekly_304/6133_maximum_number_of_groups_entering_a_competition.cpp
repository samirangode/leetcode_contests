#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int ans = 1;
        int lo = 0, high = 500;
        int mid = 0; int val = 0;
        while(lo<=high){
            mid = lo + (high-lo)/2;
            val = (mid*(mid+1))/2;
            if(val==n) return mid;
            else if(n>val){
                ans = max(ans, mid);
                lo = mid+1;
            }
            else if(n < val){
                high = mid - 1;
            }
        }
        return ans; 
    }
};
