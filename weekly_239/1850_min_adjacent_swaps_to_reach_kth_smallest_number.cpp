#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSteps(string s1, string s2){
        int n = s1.length();
        int i = 0; int j = 0;
        int result  = 0;
        
        while (i<n)
        {
            while(s1[i]!=s2[j]) j++;
            while(j>i){
                swap(s2[j],s2[j-1]);
                j--;
                result++;
            }
            i++;
        }
        return result;

    }
    int getMinSwaps(string num, int k) {
        string original = num;

        while(k--){
            next_permutation(num.begin(),num.end());
        }
        return minSteps(original, num);
    }
};