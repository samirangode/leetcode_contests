#include <iostream>
#include <string>
#include <vector> 

bool isPalindrome(string s){
    for(int i = 0 ; i < s.size()/2; i++){
        if(s[i] != s[s.size()-1 -i]){
            return false;
        }
    }
    return true;
}


class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i = 0; i < words.size(); i++){
            if(isPalindrome(words[i])){
                return words[i];
            }
        }
        return "";
    }
};