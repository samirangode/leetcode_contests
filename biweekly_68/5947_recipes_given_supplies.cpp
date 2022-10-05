#include <string>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        // unordered_set<string> recipes_map(recipes.begin(),recipes.end());
        unordered_map<string,int> recipes_map;
        for(int j = 0; j<recipes.size();j++){
            recipes_map[recipes[j]] = j;
        }
        unordered_set<string> supplies_set(supplies.begin(),supplies.end());
        vector<string> ans;
        for(int i = 0; i< recipes.size(); i++){
            bool flag_all_present = true;
            for(string ingredient: ingredients[i]){
                auto it = recipes_map.find(ingredient);
                
                if(supplies_set.find(ingredient)==supplies_set.end() && it==recipes_map.end()){
                    flag_all_present = false;

                    break;
                }
                if(it!= recipes_map.end()){
                    int j = it->second;
                    for(string bleh : ingredients[j]){
                        if(bleh==recipes[i]){
                            cout<<"I am here for the recipe " << recipes[i]<<" and "<< bleh<<endl;
                            flag_all_present = false;
                            break;
                        }
                    }

                }

            }
            if(!flag_all_present){
                recipes_map.erase(recipes[i]);
            }
        }

    ///after those without recipes or supplies are removed
        for(int i = 0; i< recipes.size(); i++){
            bool flag_all_present = true;
            for(string ingredient: ingredients[i]){
                auto it = recipes_map.find(ingredient);
                if(it == recipes_map.end()){
                    flag_all_present = false;
                }
                if(it!= recipes_map.end()){
                    int j = it->second;
                    for(string bleh : ingredients[j]){
                        if(bleh==recipes[i]){
                            cout<<"I am here for the recipe " << recipes[i]<<" and "<< bleh<<endl;
                            flag_all_present = false;
                            break;
                        }
                    }

                }
            }
            if(flag_all_present){
                ans.push_back(recipes[i]);
            }
        }

    return ans;
    }
};