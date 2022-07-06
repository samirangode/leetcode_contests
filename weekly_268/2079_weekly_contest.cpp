#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int vol = capacity;
        int refill = 0;
        int steps = 0;
        int i = 0;
        int n = plants.size();
        while(i<n){
            if(vol>=plants[i]){
                vol = vol - plants[i];
                steps++;
                i++;
            }
            else{
                steps = 2*i;
                vol = capacity - plants[i];
                steps++;
                i++;
                refill++;
            }
        }
        return steps;
    }
};