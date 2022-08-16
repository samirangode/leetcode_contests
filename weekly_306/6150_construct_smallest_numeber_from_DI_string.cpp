#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string curr = "";
        unordered_set<int>
        if(pattern[0]=='I'){
            string temp(n+1,'1');
            curr = temp;
            f(0, curr, pattern);
        }
        if(pattern[0]=='D'){
            string temp(n+1,'2');
            curr = temp;
            f(0, curr, pattern);
        }
        return curr;      
    }
    bool f(int i, string &curr, string pattern, unordered_set<int > & us){
        if(i == pattern.size()) return true;

        int num = curr[i] - '0';
        if(pattern[i]=='I'){
            while(num<9){
                curr[i+1] = (++num  +'0');
                if(f(i+1, curr, pattern)) {

                }
            }
            if (num>=9) return false;
        }
        else if(pattern[i]=='D'){
            while(num>1){
                curr[i+1] = (--num + '0');
                if(f(i+1, curr, pattern)) break;
            }
            if(num<=1) return false;
        }
        return true;
    }
};
