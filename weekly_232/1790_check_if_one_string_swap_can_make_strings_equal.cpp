#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size()!= s2.size()){
            return false;
        }
        int n = s1.size();
        int count = 0;
        unordered_set<char> one;
        unordered_set<char> two;
        for(int i = 0; i< n; i++){
            if(s1[i]!=s2[i]){
                count ++;
                if(count>2) return false;
                one.insert(s1[i]); two.insert(s2[i]);
            }
        }
        if(one!=two) return false;

        return true;      
    }
};
