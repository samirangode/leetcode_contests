#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        priority_queue<int> pq;
        for(int num : nums){
            pq.push(num);
        }
        int temp;
        while(maxOperations>0){
            temp = pq.top();
            pq.pop();
            pq.push(temp/2);
            pq.push(temp - temp/2);
            maxOperations--;
        }
        return pq.top();      
    }
};
