#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        bool ans = true;
        sort(asteroids.begin(),asteroids.end());
        long long totalMass = mass;
        for(int i : asteroids){
            if(totalMass>=i){
                totalMass +=i;
            }
            else{
                ans = false;
            }
        }
        return ans;
    }
};