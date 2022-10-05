#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int A = 0;
        int B = plants.size() - 1;
        int vala = capacityA;
        int valb = capacityB;
        int refills = 0;
        while(A<plants.size()-1 && A<=B && B>0){
            if(A==B){
                if(vala>valb && vala> plants[A]){
                    vala = vala - plants[A];
                    A++;    
                }
                if(valb>vala && valb> plants[B]){
                    valb = valb - plants[B];
                    B--;    
                }
                if(vala == valb && vala > plants[A]){
                    vala = vala - plants[A];
                    A++;
                }
                if(vala<plants[A] && valb < plants[B]){
                    refills++;
                    vala = capacityA-plants[A];
                    A++;    
                }

                continue;
            }
            if(plants[B]<valb){
                valb = valb - plants[B];
                B--;
            }
            if(plants[A]<vala){
                vala = vala - plants[A];
                A++;
            }
            if(plants[A]>vala){
                refills++;
                vala = capacityA-plants[A];
                A++;
            }
            if(plants[B]>valb){
                refills++;
                valb = capacityB - plants[B];
                B--;
            }
        }
        return refills;
    }
};