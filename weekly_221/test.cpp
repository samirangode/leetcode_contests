#include <bits/stdc++.h>

using namespace std;

int main(){
    // vector<int> arr;
    int x = 5;
    int val = 0;
    for(int i = 1; i<=10; i++){
        val = i^x;
        cout<<val<<endl;
    }
    
    return 0;
}