#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        unordered_map<string, int> um;
        um.insert({"type",0}); um.insert({"color", 1}); um.insert({"name",2});
        int val = um[ruleKey];
        int count = 0;
        for(int i = 0; i < items.size(); i++){
            if(ruleKey == items[i][val])
                count++;   
        }

        return count;     
    }
};