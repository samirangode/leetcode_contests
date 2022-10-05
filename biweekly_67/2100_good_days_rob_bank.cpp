#include <vector>
#include <bits/stdc++.h>
// sliding window.
using namespace std;
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> decreasing_window;
        vector<int> increasing_window;
        for(int i = 0; i<time; i++){
            decreasing_window.push_back(security[i]);
            increasing_window.push_back(security[time + 1 + i]);
        }
        vector<int> ans;
        for(int i = 0; i<security.size()-time; i++){
            
        }
    }
};