#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        set<int> s;
        for(int i =0; i<n;i++){
            s.insert(i+1);
        }
        while(s.size()!=1){
            auto it = s.begin();
            n =s.size();
            for(int i = 0; i<k%n; i++){
                it++;
            }
            
            s.erase(*it);
        }
        auto it = s.begin();
        it++;
        return *it;        
    }
};
