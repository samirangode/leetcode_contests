#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int columnns = encodedText.length()/rows;
        int i = 0;
        int j_min = 0;
        int j = 0;
        string s = "";
        while(j<columnns){
            i = 0; j = j_min;
            while(i < rows){
                s = s + encodedText[i*4 + j];
                i++;
                j++;
            }
            j_min++;
        }
        i = 0; j = j_min;
        while(j<columnns){
            s = s + encodedText[i*4 + j];
            i++;
            j++;
        }
        // string whitespace = " ";
        int end = s.find_last_not_of(" ");
        s = s.substr(0, end+1);        
        return s;
    }
};
