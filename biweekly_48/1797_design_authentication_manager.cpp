#include <bits/stdc++.h>

using namespace std;

class AuthenticationManager {
public:
    int ttl;
    map<int,string> time_token;
    unordered_map<string,int> token_time;
    void clean(int currentTime){
        auto it = time_token.begin();
        int temp_time;
        string temp_token;
        while(it->first<currentTime){
            temp_time = it->first; temp_token = it->second;
            it++;
            token_time.erase(temp_token);
            time_token.erase(temp_time);
        }
    }
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        time_token.insert({currentTime+ttl,tokenId});
        token_time.insert({tokenId,currentTime+ttl});
        clean(currentTime);
    }
    
    void renew(string tokenId, int currentTime) {
        clean(currentTime);
        if(token_time.find(tokenId)!=token_time.end()){
            time_token.erase(token_time[tokenId]);
            time_token[currentTime+ttl] = tokenId;
            token_time[tokenId] = currentTime + ttl;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        clean(currentTime);
        int count = 0;
        for(auto it : token_time){
            count++;
        }
        return count;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */