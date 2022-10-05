#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int j = 0;
        int i = 0;
        int max_dist = 0;
        while(j<n || i<m ){
            while(j<n && nums2[j]>=nums1[i]){
                j++;
            }
            max_dist = max(max_dist, j-i);
            i++;

        }
        return max_dist;        
    }
};