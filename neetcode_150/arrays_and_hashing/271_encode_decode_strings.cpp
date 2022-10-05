#include <bits/stdc++.h>

using namespace std;

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        int n = strs.size();
        string encoded = "";
        encoded= encoded + to_string(n) + "|";
        string combined = "";
        for(int i =0 ; i<n; i++){
            combined +=strs[i];
            encoded = encoded + to_string(strs[i].size()) + ".";
        }
        encoded = encoded + "|" + combined;
        return encoded;

    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int k = 0;
        for(char c : s){
            k++;
            if(c=='|'){
                break;
            }
        }
        int num_string = stoi(s.substr(0,k));
        vector<string> ans(num_string,"");
        string curr_string = "";
        vector<int> sizes; 
        int i = 0;
        for(i = k; s[i]!='|';i++){
            if(s[i]=='.'){
                sizes.push_back(stoi(curr_string));
                curr_string = "";
                continue;
            }
            curr_string+=s[i];
        }
        i++;
        int j = 0;
        while(j<num_string){
            ans[j] = s.substr(i,sizes[j]);
            i+=sizes[j];
            j++;
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
