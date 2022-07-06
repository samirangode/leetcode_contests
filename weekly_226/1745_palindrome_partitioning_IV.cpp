#include <bits/stdc++.h>

using namespace std;

// bool isPalindrome(string s){
//     bool ans = true;
//     int n = s.length();
//     for(int i =0; i<n/2; i++){
//         if(s[i]!=s[n-1-i]){
//             ans = false;
//             return ans;
//         }
//     }
//     return ans;
// }


// class Solution {
// public:
//     bool ans = false;
//     int helper(string s, int i, int n){
//         if(i == n) return 0;
//         string temp = "";
//         int cost = 0;
//         for(int j = i; j<n; j++){
//             temp+=s[j];
//             if(isPalindrome(s)){
//                 cost = 1 + helper(s,j+1,n);
//             }
//             if(cost==3){
//                 ans = true;
//                 return 0;
//             }
//         }
//     }
//     bool checkPartitioning(string s) {

//     }
// };

class Solution {
public:
    vector<vector<int>> dp;
    bool isPalindrome(string &s, int i, int j){
        if(i>=j) return true;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]== s[j]) return dp[i][j] == isPalindrome(s, i+1, j-1);
        return dp[i][j] = false;
    }
    bool checkPartitioning(string s) {
        int n = s.length();
        dp.resize(n,vector<int>(n,-1));
        for(int i = 0; i<n; i++){
            for(int j = i+1;j<n; j++){
                if(isPalindrome(s, 0, i) && isPalindrome(s,i+1,j) && isPalindrome(s, j+1, n-1))
                    return true; 
            }
        }
        return false;
    }
};
