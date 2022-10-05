#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.length();
        int m = word.length();
        int i = 0, j= 0;
        int max_k = 0;
        int k = 0;
        while(i < n && j < n){
            k = 0; j = i;
            while(j<n && sequence.substr(j,m) == word){
                k++; max_k = max(max_k, k);
                j+=m;
            }
            i++;
        }
        return max_k;      
    }
};