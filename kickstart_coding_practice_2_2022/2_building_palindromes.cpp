#include <bits/stdc++.h>

using namespace std;




int main(){
    int T;
    cin>>T;
    for(int tc = 1; tc<=T;tc++){
        cout << "Case #" << tc << ": " << getMaximumBalancedSubstrings(L, R) << endl;
    }
}