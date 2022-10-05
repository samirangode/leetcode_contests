#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int MAXN= 1e5 +1; 
    const int MOD = 1e9 +7;
    int sumOfFlooredPairs(vector<int>& nums) {
        int maxi = 0;
        vector<long long> freq(2*MAXN + 1);
        for(auto num : nums){
            ++freq[num];
            maxi = max(maxi, num);
        }
        for(int i = 1; i<=2*MAXN; i++){
            freq[i]+=freq[i-1];
        }
        int ans = 0;
        unordered_map<int,int> um;
        for(auto num : nums){
            
            if(um.find(num)==um.end()){
                long l = num-1; long r = 2*num-1; long div = 1;
                int temp_sum = 0;
                while(l<maxi){
                    temp_sum = (temp_sum + div * (freq[r] - freq[l]))%MOD;
                    l+= num;
                    r+= num;
                    ++div;
                }
                ans+= temp_sum;
                um.insert({num,temp_sum});
            }
            else{
                ans += um[num];
            }
        }
        return ans;
    }
};