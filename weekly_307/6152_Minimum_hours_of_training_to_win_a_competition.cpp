#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestPalindromic(string num) {
        int n = num.length();
        unordered_map<char, int> um;
        int num_0 = 0;
        for(int i = 0; i<n; i++){
            if(num[i]!='0'){
                um[num[i]]++;
            }
            if(num[i]==0){
                num_0++;
            }
        }
        string palindrome = "";
        int temp = 0;
        bool middle = false;
        char max_val = '0' - 1;
        for(auto it : um){
            if(it.second>=2){
                temp = it.second;
                temp = temp/2;
                while(temp>0){
                    palindrome+= it.first;
                    temp--;
                }
            }
            if(it.second%2>0){
                max_val = max(max_val, it.first);
                middle = true;
            }
        }
        if(palindrome.length()>0 && num_0 > 0){
            temp = num_0;
            temp = temp/2;
            while(temp>0){
                palindrome+='0';
                temp--;
            }
            if(!middle && num_0%2 > 0){
                max_val = '0';
                middle = true;
            }
        }

        sort(palindrome.begin(), palindrome.end(), greater<int>());
        // mid value causing an issue
        // for(auto it : um){
        //     if(it.second%2 > 0){
        //         if(it.first>max_val){
        //             palindrome+=it.first;
        //             middle = true;
        //             break;
        //         }
        //     }
        // }
        //////
        int m = palindrome.length()-1;
        if(middle) m = m -1;
        for(int i = m ; i>=0; i--){
            palindrome+=palindrome[i];
        }
        return palindrome;
    }
};
