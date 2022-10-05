#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        int vowels = 0;
        unordered_set<char> us;
        for (char i : "aeiouAEIOU"){
            us.insert(i);
        }
        for(int i = 0; i <n ;i++){
            if(us.find(s[i])!= us.end()){
                vowels++;
            }
        }
        if(vowels>0 && vowels%2 ==0){
            return true;
        }
        else{
            return false;
        }      
    }
};
