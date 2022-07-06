#include <string>
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int countPoints(string rings) {
        string rods[10] = {};
        
        // for(int i = rings.length()-1; i>0; i--){
        //     if
        // }
        int i = rings.length()-1;
        while(i>0){
            rods[int(rings[i])] += rings[i-1];
            i -=2;
        }
        int ans = 0;
        for(int j = 0; j < 10; j++){
            sort(rods[j].begin(),rods[j].end());
            if( rods[j] == "bgr"){
                ans+=1;
            }
        }
    return ans;
    }
};

int main(){
    return 0;
}