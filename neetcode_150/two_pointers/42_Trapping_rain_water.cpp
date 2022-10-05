#include <bits/stdc++.h>

using namespace std;

///////////////////////DP solution
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         if(n == 0){
//             return 0;
//         }
//         int ans = 0;
//         vector<int> left_max(n), right_max(n);
//         left_max[0] = height[0];
//         right_max[n-1] = height[n-1];
//         for(int i = 1; i< n; i++){
//             left_max[i] = max(height[i],left_max[i-1]);
//         }
//         for(int i = n-2; i>=0; i--){
//             right_max[i] = max(height[i], right_max[i+1]);
//         }
//         for(int i = 1; i< n-1; i++){
//             ans+= min(left_max[i],right_max[i]) - height[i];
//         }
//         return ans;
//     }
// };
/////////////////////////// 2 Pointer Solution
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left_max = INT_MIN;
        int right_max = INT_MIN;
        int left = 0, right = n-1;
        int ans = 0;
        while(left<right){
            if(left_max<=right_max){
                if(height[left]>left_max){
                    left_max = height[left];
                }else{
                    ans+= left_max -height[left];
                    left++;
                }
            }else{
                if(height[right]>right_max){
                    right_max = height[right];
                }else{
                    ans+=right_max - height[right];
                    right--;
                }
            }
            return ans;
        }
        
    }
};
