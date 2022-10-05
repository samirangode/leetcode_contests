#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string capitalizeTitle(string title) {
        string word;
        string ans = "";
    
        stringstream iss(title);
 
    
        while (iss >> word){
        
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            if(word.length()>2){
                word[0] = toupper(word[0]);
            }
            ans = ans + word;
        }
        return ans;
    }
};