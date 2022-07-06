#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        bool crash = false;
        int allocated = 0;
        int mem;
        int i = 0;
        while(!crash){
            allocated = i+1;
            if(memory2>memory1){
                if(memory2>=allocated){
                    memory2-=allocated;
                }
                else{
                    crash = true;
                }
            }
            else{
                if(memory1>=allocated){
                    memory1-=allocated;
                }
                else{
                    crash = true;
                }
            }

            i++;
        }
        vector<int> ans;
        ans.push_back(i);
        ans.push_back(memory1);
        ans.push_back(memory2);      
    }
};