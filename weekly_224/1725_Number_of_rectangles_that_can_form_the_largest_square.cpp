#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxLen = 0; int len = 0;
        int count = 0; int n = rectangles.size();
        for( int i = 0; i <n;i++){
            len = min(rectangles[i][0], rectangles[i][1]);
            if(len>maxLen){
                maxLen = len;
                count = 1;
            }
            if(len==maxLen){
                count++;
            }
        }
        return count;      
    }
};
