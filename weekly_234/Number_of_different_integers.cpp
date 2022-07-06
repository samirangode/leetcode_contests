#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numDifferentIntegers(string word) {
        int n = word.length();
        for(int i = 0; i<n;i++){
            if(word[i]>'9' || word[i]<'0'){
                word[i] = ' ';
            }
        }
        stringstream s(word);
        string w;
        int count = 0;
        unordered_set<int> us;
        while(s>>w){
            count++;
            us.insert(stoi(w));
        }        
        return us.size();      
    }
};