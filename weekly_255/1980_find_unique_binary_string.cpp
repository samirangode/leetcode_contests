#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string ans;
    void binaryHelper(string s, int n, unordered_set<string> us,bool& flag){
        if(flag){
            return;
        }
        if(s.length() == n){
            if(us.find(s) == us.end()){
                flag = true;
                ans = s;
                return;
            }
            return;
        }
        binaryHelper(s + "0", n, us, flag);
        binaryHelper(s + "1", n, us, flag);
        return;
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> us;
        for( auto &s : nums){
            us.insert(s);
        }
        bool flag = false;
        binaryHelper("",nums.size(),us,flag);
        return ans;
    }
};

