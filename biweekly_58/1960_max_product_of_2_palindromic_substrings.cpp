#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxProduct(string s) {
        int n = s.length();
        bool table[n][n];
        memset(table, 0, sizeof(table));
        int maxLength = 1;
        for(int i = 0; i <n; i++){
            table[i][i] = true;
        }
        int start = 0;
        vector<int> maxtill(n);
        vector<int> maxafter(n);
        for(int i = 0; i<n; i++){
            maxtill[i] = 1;
            maxafter[i] = 1;
        }

        int start = 0;
        maxtill[0] = 1;
        for( int i =0; i<n-1; ++i){
            if(s[i]==s[i+1]){
                table[i][i+1] = true;
                start =i;
                maxLength =2;
                if(i == 0){
                    maxtill[1] = 2;
                }
                maxafter[i] = 2;
            }
        }
        int length = 0;
        for(int i = 0; i < n -2 ; i++){
            for(int j = i+2; j<n; j++){
                if(table[i+1][j-1] && s[i]==s[j]){
                    table[i][j] = true;
                    length = j - i +1;
                    maxtill[j] = max(maxtill[j],length);
                    maxafter[i] = max(maxafter[i], length);
                    
                }

            }
        }
        long long ans = 1;
        for(int k = 1; k <=n-1 ; k++){
            ans = max(ans, 1ll*maxtill[k-1]*maxafter[k]);
        }
        return ans;



    }
};