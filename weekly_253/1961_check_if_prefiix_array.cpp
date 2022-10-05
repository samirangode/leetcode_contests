#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string check = "";
        for(string word : words){
            check+=word;
            if(check==s){
                return true;
            }
        }
        return false;
    }
};