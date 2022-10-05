#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        int i = 0;
        int j = 0;
        int k = 0;
        int loc = 0;
        vector<int> stone;
        while(i<m){
            while(j<n){
                while(box[i][j]!='*'){
                    if(box[i][j]=='#'){
                        stone.push_back(j);
                    }
                    j++;
                }
                loc = j;
                while(!stone.empty()){
                    k = stone.back();
                    box[i][k] = '.';
                    box[i][loc-1] = '#';
                    loc--;
                    stone.pop_back();
                }
                j++;
            }
            while(!stone.empty()){
                k = stone.back();
                box[i][k] = '.';
                box[i][j-1] = '#';
                j--;
                stone.pop_back();
            }
            i++;
        }
        vector<vector<char>> ans(n, vector<char>(m,'.'));
        for(int x = 0; x< m; x++){
            for(int y = 0; y<n; y++){
                ans[y][n-x] = box[x][y];
            }
        }
        return ans;
    }
};
