#include <bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     int countVowelSubstrings(string word) {
//         int val = 0;
//         int n = word.length();
//         unordered_set<char> us;
//         us.insert('a'); us.insert('e'); us.insert('i'); 
//         us.insert('o'); us.insert('u');
//         for(int i = 0; i<n; i++){
//             string vowels = "";
//             bool all = false;
//             for(int j = i; j<n; j++){
//                 if(us.find(word[j])==us.end()){
//                     break;
//                 }
//                 else{
//                     vowels = vowels + word[j];

//                 }
//             }
//         }        
//     }
// };
//better solution

class Solution {
private:
    bool isVowel(char c){
        if(c=='a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            return true;
        }
        else{
            return false;
        }
    }

    int countAtMostKVowel(string s, int k){
        int i = 0;
        int n = s.length();
        int count = 0;
        unordered_map<char,int> um;
        for(int j = 0; j < n; j++){
            um.clear();
            if(!isVowel(s[j])){
                i = j+1;
                continue;
            }

            um[s[j]]++;

            while(um.size()<k){
                um[s[i]]--;
                if(um[s[i]]==0){
                    um.erase(s[i]);
                }
                i++;
            }
            count += j-i +1;
        }
        return count;
    }

public:
    int countVowelSubstrings(string word) {
        return countAtMostKVowel(word, 5) - countAtMostKVowel(word, 4);
        

    }
};