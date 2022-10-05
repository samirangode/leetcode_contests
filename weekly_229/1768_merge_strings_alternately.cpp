#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans ="";
        int m = word1.length();
        int n = word2.length();
        int i = 0; int j = 0;
        while(i<m || j<n){
            if(i<m) ans+=word1[i];
            if(j<n) ans+=word2[j];
            i++;j++;
        }
        return ans;
    }
};
