#include <bits/stdc++.h>

using namespace std;

class Solution {

private:
    int check(string s, vector<vector<int>> statements){
        int n = statements.size();
        int count = 0;
        for(int i = 0 ; i <n ; i++){
            if(s[i] ==0){
                continue;
            }
            count++;
            for(int j = 0; j<n ; j++){
                if((statements[i][j]==1 && s[j]==0) || (statements[i][j]==0 && s[j]==1)){
                    return 0;
                }
            }

        }
        return count;
    }

    int maxGoodHelper(int index, string s, vector<vector<int>> &statements){
        if(index == statements.size()){
            return check(s,statements);
        }
        int bad = maxGoodHelper(index+1, s + "0", statements);
        int good = maxGoodHelper(index + 1, s + "1", statements);

        return max(good,bad);
    }

public:
    int maximumGood(vector<vector<int>>& statements) {
        return maxGoodHelper(0,"",statements);
    }
};