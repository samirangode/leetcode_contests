#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        // int m = sandwiches.size();
        queue<int> q;
        for(int i =0; i<n;i++){
            q.push(students[i]);
        }
        // for(int i =0 ; i<n;i++){
        // }
        // int curr_size = 0, prev_size = 0;
        // while((curr_size - prev_size)==0){

        // }
        int i = 0;
        while(q.size()>0 && i<n){
            if(q.front()==sandwiches[i]){
                q.pop();
                i++;
            }
            else{
                int m = q.size(), j = 0;
                int temp = q.front(); q.push(temp);
                q.pop();
                while(j<m){
                    if(q.front()==sandwiches[i]){
                        q.pop(); i++;
                        break;
                    }
                    else{
                        temp = q.front();q.push(temp);
                        q.pop();
                    }
                    j++;
                }
                if(j>=m){
                    break;
                }
            }
        }
        return q.size();        
    }
};
