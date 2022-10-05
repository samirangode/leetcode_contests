#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string getSmallestString(int n, int k) {
        unordered_map<int,char> um;
        char c = 'a';
        for(int i = 1; i <=26; i++){
            um.insert({i,c});
            c++;
        }
        string ans = "";
        int div = k/26;
        int rem = k%26;
        char diff = um[rem-(n-(div+1))];      
        while(div>0){
            ans+=um[26];
            div--;
        }
        ans = diff + ans;
        while(ans.size()<n){
            ans = um[1] + ans;
        }
        return ans;
    }
};
