#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int helper(char prev, int n, vector<int>& vowels){
        if(n==0) return 1;
        int total = 0; int n = vowels.size();
        for(int i = 0; i<n; i++){
            if(vowels[i]>=prev){
                total+=helper(vowels[i],n-1,vowels);
            }
        }
        return total;
    }
    
    int countVowelStrings(int n) {
        vector<int> vowels = {'a','e','i','o','u'};
        return helper('a'-1,n,vowels);
    }
};
