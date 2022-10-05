#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        int maxi = max(INT_MIN,differences[0]);
        int mini = min(INT_MAX, differences[0]);
        int ans = 0;
        for(int i = 1; i< n; i++){
            differences[i] = differences[i-1] + differences[i];
            mini = min(differences[i], mini);
            maxi = max(differences[i], maxi);
        }
        if((lower+mini) > upper || (lower+maxi)>upper || (upper+maxi)<lower || (upper+mini)<lower){
            return 0;
        }
        int i = lower;
        int j = upper;
        while((i+mini)<lower){
            i++;
        }
        while((j+maxi)>upper){
            j--;
        }

        return j-i+1;
                
    }
};