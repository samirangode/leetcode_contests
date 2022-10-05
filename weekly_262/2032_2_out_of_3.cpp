#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_set<int> s1(nums1.begin(),nums1.end());
        unordered_set<int> s2(nums2.begin(),nums2.end());
        unordered_set<int> s3(nums3.begin(),nums3.end());
        vector<int> ans;
        int count = 0;
        for(int i : s1){
            count = 0;
            if(s2.find(i)!=s2.end()){
                count++;
                s2.erase(i);
            }
            if(s3.find(i)!=s3.end()){
                count++;
                s3.erase(i);
            }
            if(count>=1){
               ans.push_back(i);
            }

        }
        for(int i : s2){
            count = 0;
            if(s3.find(i)!=s3.end()){
                count++;
                s3.erase(i);
            }
            if(count==1){
               ans.push_back(i);
            }
        }

        return ans;

    }
};
