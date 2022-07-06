#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string interpret(string command) {
        unordered_map<string,string> um;
        um.insert({"G","G"});
        um.insert({"()","o"});
        um.insert({"(al)","al"});
        int n = command.length();
        string ans = "";
        for(int i =0; i<n;i++){
            if(command[i]=='G'){
                ans+="G";
            }
            if(command[i]=='('){
                if(command[i+1]==')'){
                    ans+="o";
                    i+=2;
                }
                else{
                    ans+="al";
                    i+=4;
                }
            }
        }      
        return ans;
    }
};
