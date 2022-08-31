#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> v(n,0);
        int m = shifts.size();
        for(int j=0; j<m; j++){
            int num = shifts[j][2];
            if(num==0) num = -1;
            for(int k =shifts[j][0]; k<=shifts[j][1]; k++){
                v[k]+=num;
            }
        }
        int character= 0;
        for(int i = 0; i<n; i++){
            character = s[i] - 'a';
            character+=v[i];
            character = character % ('z' - 'a');
            if(character<0){
                character = 'z' + character;
            }else{
                character = character + 'a';
            }
            s[i] = character;
        }
        return s;      
    }
};
