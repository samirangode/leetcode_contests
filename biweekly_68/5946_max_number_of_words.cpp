#include <string>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int max = 0;
        for (string sen : sentences){
            int count = 0;
            istringstream iss(sen);
        do {
            string subs;
            iss >> subs;
            if(subs != ""){
                count ++;
            }
            // cout << subs << endl;
  
        } while (iss);
            if(count>max){
                max = count;
            }
        }
    return max;
    }
};