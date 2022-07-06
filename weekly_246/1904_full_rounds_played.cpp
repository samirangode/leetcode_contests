#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool sameDay(string loginTime, string logoutTime){
        int start_hour = stoi(loginTime.substr(0,2));
        int start_min = stoi(loginTime.substr(3,2));
        int end_hour = stoi(logoutTime.substr(0,2));
        int end_min = stoi(logoutTime.substr(3,2));
        if(start_hour>=end_hour && start_min>end_min){
            return true;
        }
        else{
            return false;
        }

    }
    int rounds(string loginTime, string logoutTime){
        int start_hour = stoi(loginTime.substr(0,2));
        int start_min = stoi(loginTime.substr(3,2));
        int end_hour = stoi(logoutTime.substr(0,2));
        int end_min = stoi(logoutTime.substr(3,2));

        int i = start_min/15;
        int rounds = 0;
        rounds += 4*(end_hour - (start_hour+1));
        if(start_min%15==0){rounds+=4-i;}
        else{
            rouds+=4-(i+1);
        }
        int j = end_min/15;
        rounds+=j;
        
        return rounds; 

    }
    
    
    int numberOfRounds(string loginTime, string logoutTime) {
        bool same_day = sameDay(string loginTime, string logoutTime);
        if(same_day{
            return rounds(loginTime,logoutTime);
        }
        else{
            return rounds(loginTime,"24:60")+rounds("00:00",logoutTime);
        }

    }
};
