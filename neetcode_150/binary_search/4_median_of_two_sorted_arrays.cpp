#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        // Want m to be smaller
        if(m>n){
            findMedianSortedArrays(nums2, nums1);
        }
        // we'll iterate on the smaller array
        int total = m+n;
        int low = 0, high = m;
        double result = 0.0;

        while(low<=high){
            // nums1
            int i = low + (high - low)/2 ;
            //nums2
            int j = (total+1) /2 - i;
            int left1 = (i>0) ? nums1[i-1] : INT_MIN;
            int right1 = (i<m) ? nums1[i] : INT_MAX; 
            int left2 = (j>0) ? nums2[j-1] : INT_MIN; 
            int right2 = (j<n) ? nums2[j] : INT_MAX;

            // partition is correct
            if(left1<=right2 && left2<=right1){
                if(total%2==0){
                    result = (max(left1,left2) + min(right1,right2)) / 2.0;
                }else{
                    result = max(left1, left2);
                }
                break;
            }
            else if(left1 > right2){
                high = i-1;
            } else{
                low = i+1;
            }
        }
        return result;                
    }
};
