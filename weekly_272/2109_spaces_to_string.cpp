#include <iostream>
#include <string>
#include <vector> 

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int i = 0;
        for(int pos : spaces){
            pos = pos +i;
            s.insert(pos, " ");
            i++;
        }
    return s;
    }
};

