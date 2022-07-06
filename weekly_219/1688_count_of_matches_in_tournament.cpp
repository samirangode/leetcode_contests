#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfMatches(int n) {
        int matches = 0;
        while(n>0){
            if(n==1){
                matches+=0;
                return matches;
            }
            if(n%2 == 0){
                matches += n/2;
                n = n/2;
            }
            else{
                matches = (n-1)/2;
                n = (n-1)/2 + 1;
            }
        }      
        return matches;
    }
};
