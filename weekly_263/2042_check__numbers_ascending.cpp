
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev =-1;
        bool ans = true;
        string word;
        stringstream iss(s);
        int temp = 0;
        while(iss>>word){
            if(word[0]<='9' && word[0]>='0'){
                temp = stoi(word);
                if(temp>prev){
                    prev = temp;
                }
                else{
                    ans = false;
                    break;
                }
            }
        }
        return ans;

    }
};