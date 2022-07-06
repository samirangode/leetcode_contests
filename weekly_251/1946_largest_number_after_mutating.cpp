#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        bool flag = true;
        bool possible = true;
        int i = 0;
        int n = num.length();
        int temp_num = 0;
        while(i<n){
            temp_num = num[i] - '0';
            if(change[temp_num]>temp_num){
                if(possible){
                    flag = true;
                    int temp = '0' + change[temp_num];
                    num[i] = (char)temp;
                }
            }
            else{
                if(possible&&flag){
                    flag = false;
                }                // flag = false;
            }
            if(!flag){
                break;
            }
            
            i++;
        }
        return num;

    }
};