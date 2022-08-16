#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = 0;
        int max_area = INT_MIN;
        int area = 0, temp_length = 0;
        while(i<j){
            area = (j-i)*min(height[i], height[j]);
            max_area = max(area, max_area);
            if(height[i] == min(height[i], height[j])){
                i++;
            }else{
                j--;
            }
        }
        return (max_area > 0)? max_area : 0;      
    }
};