#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int a = coordinates[0] - 'a';
        int b = coordinates[1] - '1';
        if((a+b)%2 == 0) return false;
        return true;    
    }
};
