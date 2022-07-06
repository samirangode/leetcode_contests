#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for( int  p : piles){
            pq.push(p);
        }
        int tope = 0;
        while(!pq.empty() && k>0){
            tope = pq.top();
            tope = !(tope%2) ? tope/2:(tope/2+1);
            pq.pop();
            pq.push(tope);
            k--;
        }
        int sum = 0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;        
    }
};