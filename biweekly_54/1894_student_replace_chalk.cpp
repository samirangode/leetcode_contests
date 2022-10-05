#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        // int numChalks = k;
        int i = 0;
        long long sum = 0;
        for(int j =0; j<n;j++){
            sum+=chalk[j];
        }
        long long rem = k%sum;
        long long numChalks = rem;
        for (;numChalks>0;){
            if(numChalks>=chalk[i%n]){
                numChalks-=chalk[i%n];
                if(numChalks==0){
                    return (i+1)%n;
                }
            }
            else{
                return i%n;
            }
            i++;
        }

        
    }
};