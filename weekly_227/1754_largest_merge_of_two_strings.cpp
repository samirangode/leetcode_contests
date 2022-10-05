#include <bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     string largestMerge(string word1, string word2) {
//         string merge = "";
//         int i = 0, j = 0;
//         int k1 = 0, k2 = 0;
//         int word1_length = word1.length();
//         int word2_length = word2.length();
//         bool end = false;
//         while(i < word1_length && j < word2_length){
//             if(word1[i]>word2[j]){
//                 merge += word1[i]; i++; 
//             }
//             else if( word1[i] < word2[j]){
//                 merge+= word2[j]; j++;
//             }
//             else{
//                 k1 = i; k2 = j;
//                 while(k1<word1_length && k2<word2_length && word1[k1]==word2[k2]){
//                     k1++; k2++;
//                 }
//                 if(!end && k1>=word1_length){
//                     while(k2<word2_length){
//                         if(word2[k2]>word1[i]){
//                             merge+=word2.substr(j);j = word2_length;
//                             merge+=word1.substr(i);i = word1_length;
//                             end = true; break;
//                         }
//                     }
//                 }
//                 if(!end && k2>=word2_length){
//                     while(k1<word1_length){
//                         if(word1[k1]>word2[j]){
//                             merge+=word1.substr(i); i = word1_length;
//                             merge+=word2.substr(j); j = word2_length;
//                             end = true; break;
//                         }
//                     }
//                 }
//                 if(k1>=word1_length && k2>=word2_length){
//                     merge+=word1.substr(i); i = word1_length;
//                     merge+=word2.substr(j); j = word2_length;
//                     end = true; break;
//                 }
//                 if(!end && word1[k1]>word2[k2]){
//                     merge+=word1.substr(i,k1-i+1); k1++;
//                     i = k1;
//                 }
//                 if(!end && word1[k1]<word2[k2]){
//                     merge+=word2.substr(j,k2-j+1); k2++;
//                     j = k2;
//                 }
//             }
//         }
//         if(i < word1_length){
//             merge+= word1.substr(i);
//         }
//         if(j < word2.length()){
//             merge+=word2.substr(j);
//         }
//         return merge;      
//     }
// };

class Solution {
public:
    string largestMerge(string word1, string word2) {
        if(word1.size() == 0 || word2.size() ==0){
            return word1 + word2;
        }
        if(word1> word2){
            return word1[0] + largestMerge(word1.substr(1),word2);
        }
        return word2[0] + largestMerge(word2.substr(1), word1);      
    }
};