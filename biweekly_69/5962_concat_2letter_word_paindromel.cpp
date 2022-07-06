#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_set<string> repeating;
        unordered_map<string, int> non_repeating;
        int ans = 0;
        for(string word : words){
            if(word[0]==word[1]){
                if(repeating.find(word)!=repeating.end()){
                    repeating.erase(word);
                    ans+=4;
                }
                else{
                    repeating.insert(word);
                }
            }
            else{
                string opp_word = word;
                opp_word[0] = word[1];
                opp_word[1] = word[0];
                if(non_repeating.find(opp_word)!=non_repeating.end() && non_repeating.find(opp_word)->second>0){
                    ans = ans + 4;
                    non_repeating[opp_word]--;
                }
                else{
                non_repeating[word]++;
                }
            }
        }
        if(repeating.size()>0){
            return ans + 2;
        }
        return ans;
    }
};