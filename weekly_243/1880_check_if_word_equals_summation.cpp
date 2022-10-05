#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        string s1 = "";
        string s2 = "";
        int n1 = firstWord.length();
        int n2 = secondWord.length();
        for(int i = 0; i<n1;i++){
            s1+=  to_string(firstWord[i] - '0');
        }
        for(int j =0;j<n2;j++){
            s2+= to_string(secondWord[j] - '0');
        }
        int n3 = targetWord.length();
        string s3 = "";
        for(int k = 0; k<n3; k++){
            s3+= to_string(targetWord[k] - '0');
        }
        long long s3val = stoll(s3);
        long long s1val = stoll(s1);
        long long s2val = stoll(s2);
        return s3val == (s1val + s2val);
    }
};
