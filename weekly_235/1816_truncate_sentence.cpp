#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans = "";
        int i=0;
        int j=0;
        int n = s.length();
        int last_word_start = 0;
        while(j<n){
            if(s[i]==' '){
                ans+=s.substr(i,j-last_word_start);
                last_word_start = j+1;
                i++;
                if(i==k){
                    break;
                }

                
            }
            j++;
        }
        return ans;

    }
};
