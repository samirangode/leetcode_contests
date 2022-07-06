#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        int pw = intLength%2 == 0 ? intLength/2 -1 : intLength/2 ;
        int starting = pow(10,pw);
        string ans = "";
        int ans_temp = 0; long long sol = 0 ; vector<long long > answer;
        for(int querie : queries){
            ans_temp = starting + querie -1;
            string temp = to_string(ans_temp);
            ans = temp;
            reverse(temp.begin(), temp.end());
            if(intLength%2){
                ans += temp.substr(1);
            }
            else{
                ans += temp;
            }
            // sol = stoll(ans);
            if(ans.size()==intLength) answer.push_back(stoll(ans));
            else answer.push_back(-1);
        }
        return answer;        
    }
};