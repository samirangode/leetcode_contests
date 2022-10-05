#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> s;
        for(int i = 0; i< n; i++){
            if(tokens[i][0]>='1' && tokens[i][0]<='9'){
                s.push(stoi(tokens[i]));
            }else{
                int temp = s.top();
                s.pop();
                int other;
                if(tokens[i]=="/"){
                    other = s.top(); s.pop();
                    other = other / temp;
                }else if(tokens[i]=="+"){
                    other = s.top(); s.pop();
                    other = other + temp;
                }else if(tokens[i]=="*"){
                    other = s.top(); s.pop();
                    other = other*temp;
                }
                else if(tokens[i]=="-"){
                    other = s.top(); s.pop();
                    other = other-temp;
                }
                s.push(other);
            }
        }
        return s.top();      
    }
};
