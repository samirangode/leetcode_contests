#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prevDevices = 0;
        int currDevices = 0;
        int ans = 0;
        for(string s : bank){
            if(currDevices!=0){
                prevDevices = currDevices;
            }
            int devices = 0;
            for(char c : s){
                if(c=='1') devices++;
            }
            currDevices = devices;
            if(prevDevices!=0 && currDevices !=0){
                ans += prevDevices*currDevices;
            }
        }      
        return ans;
    }
};