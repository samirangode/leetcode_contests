#include <bits/stdc++.h>

using namespace std;

bool check(int n, vector<int> pos)
{
    if(pos[0]<n && pos[1]<n){
        return true;
    }
    else{
        return false;
    }
    // element at dig position in array
    int ele = a[dig];
 
    // if k is less than
    // element at dig position
    // then we need to bring our higher ending to dig
    // and then continue further
    if (k <= ele) {
        return 1;
    }
    else {
        return 0;
    }
}
int binarySearch(vector<vector<int>> finalRefPos, vector<int> vecRef, vector<int> startPos, int l, int r, int n)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        // Check if x is present at mid
        // if (check(n, pos))
        //     return m;
        vector<int> pos = {0,0};
        pos[0] = startPos[0] + finalRefPos[m][0] - vecRef[0];
        pos[1] = startPos[1] + finalRefPos[m][1] - vecRef[1];
        // If x greater, ignore left half
        if (check(n,pos))
            l = m + 1;
 
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
 
    // if we reach here, then element was
    // not present
    return r;
}





class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> currPos = startPos;
        vector<int> refPos = {0,0};
        vector<vector<int>> finalRefPos;
        for(int k =0 ; k < s.size(); k++){
            char movement = s[k];
            if(movement=='U'){
                refPos[0]--;
            }
            if(movement=='R'){
                refPos[1]++;
            }
            if(movement=='D'){
                refPos[0]++;
            }
            if(movement=='L'){
                refPos[1]--;
            }            
            finalRefPos.push_back(refPos);
        }



    }
};

