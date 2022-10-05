#include <bits/stdc++.h>

using namespace std;

class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> p;
    int k;
    KthLargest(int k, vector<int>& nums):k(k) {
        int n = nums.size();
        for(int i : nums){
            p.push(i);
        }
        while(p.size()>k){
            p.pop();
        }

    }
    
    int add(int val) {
        p.push(val);
        while(p.size()>k){
            p.pop();
        }
        return p.top();    
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
