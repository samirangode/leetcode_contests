#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool checkPalindrome(string s){
        int n = s.length();
        for(int i = 0; i<n/2; i++){
            if(s[i]!=s[n-1-i]){
                return false;
            }
        }
        return true;
    }
    void maxProductHelper(string s, int i, string s1, string s2, int &maxi){
        if(i==s.length()){
            int multi = s1.length()*s2.length();
            if(multi<maxi){
                return;
            }
            bool a = checkPalindrome(s1);
            bool b = checkPalindrome(s2);
            if(a && b){
                maxi = max(maxi, multi);
            }
            return;
        }
        //not choosing i for either strings
        maxProductHelper(s, i+1, s1, s2, maxi);
        //choosing for s1
        maxProductHelper(s,i+1,s1+s[i], s2, maxi);
        //choosing for s2
        maxProductHelper(s, i+1, s1, s2 + s[i], maxi);
        return;
    }

public:
    int maxProduct(string s) {
        int maxi = 1;
        string s1 = "";
        string s2 = "";
        maxProductHelper(s,0,s1,s2,maxi);
        return maxi;
    }
};