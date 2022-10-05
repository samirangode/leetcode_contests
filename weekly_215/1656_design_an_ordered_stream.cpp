#include <bits/stdc++.h>

using namespace std;

class OrderedStream {
public:
    vector<string> ans;
    int i;
    OrderedStream(int n) {
        ans.resize(n);
        i = 0;        
    }
    
    vector<string> insert(int idKey, string value) {
        ans[idKey-1] = value;
        vector<string> result;
        while(ans[i].size()==5){
            result.push_back(ans[i]);
            i++;
        }
        return result;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
