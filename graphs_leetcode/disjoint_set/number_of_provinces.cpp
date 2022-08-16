#include <bits/stdc++.h>

using namespace std;

class UnionFind{
public:
    vector<int> root;
    vector<int> rank;
    unordered_set<int> s;
    UnionFind(int sz){
        rank.resize(sz,1);
        for(int i = 0; i< sz; i++){
            root.push_back(i);
        }
    };
    int find(int x){
        if(x==root[x]) return x;
        return root[x] = find(root[x]);
    }
    void unionSet(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX!=rootY){
            if(rank[rootX]>rank[rootY]){
                root[rootY] = rootX;
            }
            else if(rank[rootX]< rank[rootY]){
                root[rootX] = rootY;
            }
            else{
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }
    bool connected(int x, int y){
        return find(x) == find(y);
    }
    int numGroups(){
        int n = root.size();
        for(int i =0; i<n; i++){
            s.insert(find(i));
        }
        return s.size();
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind uf = UnionFind(n);
        for(int i = 0; i< n; i++){
            for(int j = i +1; j<n ;j++){
                if(isConnected[i][j]){
                    uf.unionSet(i,j);
                }
            }
        }
        return uf.numGroups();



    }
};
