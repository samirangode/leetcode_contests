#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        int sum = 0;
        for(int i = 0; i<32; i++){
            int ans = 0; int temp = 0;
            for(int elem : arr1){
                temp = elem & (1<<i);
                if(temp>0) ans++;
            }
            int ans2 = 0; int temp2 = 0;
            for(int elem2 : arr2){
                temp2 = elem2 & (1<<i);
                if(temp2>0) ans2++;
            }
            if((ans!=0&& ans%2!=0) || (ans2!=0 && ans2%2!=0)){
                sum+=1<<i;
            }
        }
        return sum;      
    }
};
