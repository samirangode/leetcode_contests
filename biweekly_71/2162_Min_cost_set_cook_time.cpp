#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int calcCost(int startAt, int dig1, int dig2, int dig3, int dig4, int moveCost, int pushCost){
        int currDig =startAt;
        int totalCost = 0;
        if(dig1!=0){
            if(currDig!=dig1){
                totalCost+=moveCost;
                currDig = dig1;
            }
            totalCost+=pushCost;
            if(currDig!=dig2){
                totalCost+=moveCost;
                currDig = dig2;
            }
            totalCost+=pusthCost;
            if(currDig!=dig1){
                totalCost+=moveCost;
                currDig = dig1;
            }
            totalCost+=pusthCost;
        }
        return totalCost;
    }
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int m = 0;
        int s = 0;
        int dig1,dig2,dig3,dig4 = 0;
        int totalCost = 0;
        int currDig = startAt;
        if(targetSeconds<60){
            s = targetSeconds%60;
            dig3 = s/10;
            dig4 = s%10;
            if(currDig!=dig3){
                totalCost+= moveCost;
            }
            currDig = dig3;
            totalCost+=pushCost;
            if(currDig!=dig4){
                totalCost+=moveCost;    
            }
            currDig = dig4;
            totalCost+=pushCost;
            return totalCost;
            
        }
        if(targetSeconds>=(99*60)){
            dig1 = 9;
        }        
    }
};
