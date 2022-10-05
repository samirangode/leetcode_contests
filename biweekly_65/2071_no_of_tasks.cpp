#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool check(int noOfTasks, vector<int> &tasks, vector<int> &workers, int pills, int strength){
        multiset<int> ms(workers.end()-noOfTasks, workers.end());

        for(int i = noOfTasks-1; i>=0; i--){
            auto it = ms.end();
            it--;
            if(*it<tasks[i]){
                if(pills<=0) return false;

                it = ms.lower_bound(tasks[i] - strength);
                if(it==ms.end()) return false;

                pills--;
            }
            ms.erase(it);

        }
        
        return true;
    }

public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int low = 0; int high = min(workers.size(), tasks.size());
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int ans = 0;
        int mid = 0;
        while(low<=high){
            mid = low + (high - low)/2;
            if(check(mid, tasks, workers, pills, strength)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }

        }
        return ans;
    }
};