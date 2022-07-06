#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTimeToType(string word) {
        int n = word.length();

        int diff = 13;
        //14// 26 - 14 ?// 26 - 2// 26 -24;
        int total_time = 0;
        int move = word[0] - 'a';
        move = min(move, 26 - move);
        total_time+=move;
        for(int i = 1; i < n; i++){
            diff = word[i] - word[i-1];
            move = min(diff, 26 - diff);
            total_time+=move;
        }
        total_time+=word.length();
        return total_time;
    }
};