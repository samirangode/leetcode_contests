#include <bits/stdc++.h>
#include <iostream>

using namespace std;


void findEvenHelper(string &chosen, vector<int> &digits_copy, set<int> &answer){
    if(chosen.length()>0 && chosen[0]=='0'){
        return;
    }
    if(chosen.length()==3){
        int ans = stoi(chosen);
        if(ans%2 == 0)
        {    answer.insert(ans);
            return;
        }
        else{
        return;}
    }
    if(chosen.length() + digits_copy.size() < 3){
        return;
    }
    for(int i = 0; i< digits_copy.size(); i++){
        int dig = digits_copy[i];
        // digits_copy.pop_back();
        chosen = chosen + to_string(dig);
        digits_copy.erase(digits_copy.begin() + i);

        findEvenHelper(chosen, digits_copy, answer);

        digits_copy.insert(digits_copy.begin() + i,dig);
        chosen.pop_back();
        // chosen.pop_back();
        // findEvenHelper(chosen,digits_copy, answer);
    }
    return;

}





class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> digits_copy = digits;
        set<int> answer;
        string chosen = "";
        findEvenHelper(chosen, digits_copy, answer);
        vector<int> final(answer.begin(),answer.end());
        return final;
    }
};

