#include "poker.h"
#include <iostream>
using namespace std;
int main(){
    int flag = 0;
    poker p;
    while(flag!=2){
        flag = 0;
        p.setpoker();
        p.shuffle();
        while(flag!=1&&flag!=2){
            p.input();
            p.save();
            p.print();
            flag = p.choice();
        }
    }
}
