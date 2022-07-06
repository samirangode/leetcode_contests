#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> old = nums;
        sort(nums.begin(), nums.end());
        vector<int> ans;
        unordered_multiset<int> s;
        for (int i = 0; i < k; i++){
            s.insert(nums[nums.size()-1-i]);
        }
        for (int i = 0; i <old.size(); i++){
            if(s.empty()){
                break;
            }
            unordered_multiset<int>::iterator it1;
            it1 = s.find(old[i]);
            if(it1!=s.end()){
                ans.push_back(old[i]);
                s.erase(it1);
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}