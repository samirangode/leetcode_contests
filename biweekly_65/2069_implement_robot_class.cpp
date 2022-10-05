#include <bits/stdc++.h>

using namespace std;

class Robot {
private:
    int w;
    int h;
    int x;
    int y;
    int dir;
public:
    
    Robot(int width, int height) {
        w = width;
        h = height;
        x = 0;
        y = 0;
        dir = 0;
    }
    
    void step(int num) {
        int steps = 0;
        while(steps<num){
            if(x>w || y>h){
                cout<<"invalid"<<endl;
                break;
            }
            if(dir == 0){
                if(x+1<w){
                    x = x+1;
                    steps++;
                }
                else{
                    dir = 1;
                }
            }
            if(dir ==1){
                if(y+1<h){
                    y = y + 1;
                    steps ++;
                }
                else{
                    dir = 2;
                }
            }
            if(dir ==2 ){
                if(x-1>0){
                    x = x-1;
                    steps++;
                }
                else{
                    dir = 3;
                }
            }
            if(dir ==3){
                if(y-1>0){
                    y = y-1;
                    steps++;
                }
                else{
                    dir = 0;
                }
            }
        }
    }
    
    vector<int> getPos() {
        vector<int> arr_pos = {x,y};
        return arr_pos;
    }
    
    string getDir() {
        string arr_dir[4] = {"East", "North", "West", "South"};
        return arr_dir[dir];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */