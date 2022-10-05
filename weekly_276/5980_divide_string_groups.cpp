#include <bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     vector<string> divideString(string s, int k, char fill) {
//         vector<string> ans;
//         int nums = s.length()/k;
//         int i  = 0;
//         while(i<k-1){
//             ans.push_back(s.substr(k*i,k*i+3));
//         }
        
//             string last = s.substr((nums-1)*k);
//             int siz = last.length();
//             while(siz<k){
//                 last = last + fill;
//                 siz ++;
//             }
//             ans.push_back(last);
//         return ans;
//     }
// };class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int nums = s.length()/k;
        int i  = 0;
        while(i<k-1){
            ans.push_back(s.substr(k*i,k*i+3));
        }
        if(s.length()%k==0){
            ans.push_back(s.substr(k*(nums-1),k*(nums-1)+3));
        }
        else{
            string final = s.substr(k*(nums-1));
            while(final.length()<k){
                final+=fill;
            }
            ans.push_back(final);
        }
        return ans;
    }
};
