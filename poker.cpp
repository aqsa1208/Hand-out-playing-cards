#include "poker.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

 void poker::setpoker(){
     int a,b;
     for(a=0;a<13;a++){
        for(b=0;b<4;b++){
            card[a][b] = 0;
        }
     }
     c = 52;
     int n[52] = {0};
     int s[52] = {0};
}

void poker::input(){
    if(c>0){
        cout<<"請輸入總共要的張數(1~52)(目前有"<< c <<"張)：";
        cin>>total;
        cout<<endl;
        cout<<"請輸入每排張數：";
        cin>>amount;
        cout<<endl;
        if(total>c||total<1||amount>total||amount<1){
            cout<<"請輸入符合範圍的張數！"<<endl;
            cout<<endl;
            input();
        }
    }
    else{
        c = 0;
    }
}

int poker::choice(){
    if(c==0){
        cout<<"目前已無牌，是否要重新洗牌(1:重新洗牌 2:結束程式)：";
        cin>>action;
        cout<<endl;
        if(action==1||action==2)
            return action;
        else{
            while(1){
                cout<<"請輸入正確的數字：";
                cin>>action;
                cout<<endl;
                if(action==1||action==2){
                    return action;
                    break;
                }
            }
        }
    }
    else{
        cout<<"是否要繼續發牌？(0:繼續發牌 1:重新洗牌 2:結束程式)：";
        cin>>action;
        cout<<endl;
        if(action==0){
            return action;
        }
        else if(action==1||action==2){
            return action;
        }
        else{
            while(1){
                cout<<"請輸入正確的數字：";
                cin>>action;
                cout<<endl;
                if(action==0){
                    return action;
                    break;
                }
                else if(action==1||action==2){
                    return action;
                    break;
                }
            }
        }
    }
}
void poker::shuffle(){
    int i,n,s;
    srand(time(NULL));
    for(i=1;i<=52;i++){
        n = rand()%13;
        s = rand()%4;
        if(card[n][s]==0){
            card[n][s] = i;
        }
        else
            i--;
    }
}

void poker::save(){
    int i,j,k;
    row = total/amount;
    if(total%amount!=0)
        row = row+1;
    for(i=1;i<=52;i++){
        for(j=0;j<13;j++){
            for(k=0;k<4;k++){
                if(card[j][k]==i){
                    n[i-1] = j+1;
                    s[i-1] = k+1;
                }
            }
        }
    }
}

void poker::print(){
    int r,i,j,k,begin_r,end_r;
    begin_r = 52-c;
    end_r = amount + begin_r;
    for(k=1;k<=row;k++){
        for(r=1;r<=11;r++){
            switch(r){
            case 1:
                for(j=begin_r;j<end_r;j++){
                cout<<"───────────"<<"   ";
                }
                cout << endl;
                break;
            case 2:
                for(j=begin_r;j<end_r;j++){
                    if(n[j]>=2&&n[j]<10){
                        cout<<"▏";
                        for(i=0;i<3;i++){
                           cout<<n[j]<<" ";
                        }
                        cout<<n[j]<<" ▕";
                        cout<<"  ";
                    }
                    else if(n[j] == 10){
                        cout<<"▏";
                        for(i=0;i<2;i++){
                            cout<<n[j]<<" ";
                        }
                        cout<<n[j]<<"▕";
                        cout << "  ";
                    }
                    else if(n[j] == 1){
                        cout<<"▏";
                        for(i=0;i<3;i++){
                            cout<<"A ";
                        }
                        cout<<"A"<<" ▕";
                        cout<<"  ";
                    }
                    else if(n[j] == 11){
                        cout<<"▏";
                        for(i=0;i<3;i++){
                            cout<<"J ";
                        }
                        cout<<"J"<<" ▕";
                        cout<<"  ";
                    }
                    else if(n[j] == 12){
                        cout<<"▏";
                        for(i=0;i<3;i++){
                            cout<<"Q ";
                        }
                        cout<<"Q"<<" ▕";
                        cout<<"  ";
                    }
                    else if(n[j] == 13){
                        cout<<"▏";
                        for(i=0;i<3;i++){
                            cout<<"K ";
                        }
                        cout<<"K"<<" ▕";
                        cout<<"  ";
                    }

                }
                cout << endl;
                break;
            case 3:
                for(j=begin_r;j<end_r;j++){
                    cout<<"▏        ▕"<<"  ";
                }
                cout<<endl;
                break;
            case 4:
                for(j=begin_r;j<end_r;j++){
                    if(s[j]==2){
                        cout<<"▏ *   *  ▕"<<"  ";
                    }
                    else {
                        cout<<"▏   *    ▕"<<"  ";
                    }
                }
                cout <<endl;
                break;
            case 5:
                for(j=begin_r;j<end_r;j++){
                    if(s[j]==1){
                        cout<<"▏  * *   ▕"<<"  ";
                    }
                    else if(s[j]==2){
                        cout<<"▏*  *  * ▕"<<"  ";
                    }
                    else if(s[j]==3){
                        cout<<"▏  * *   ▕"<<"  ";
                    }
                    else if(s[j]==4){
                        cout<<"▏* * * * ▕"<<"  ";
                    }
                }
                cout <<endl;
                break;
            case 6:
                for(j=begin_r;j<end_r;j++){
                    if(s[j]==1||s[j]==2||s[j]==3){
                        cout<<"▏ *   *  ▕"<<"  ";
                    }
                    else if(s[j]==4){
                        cout<<"▏ * * *  ▕"<<"  ";
                    }
                }
                cout <<endl;
                break;
            case 7:
                for(j=begin_r;j<end_r;j++){
                    if(s[j]==1||s[j]==4){
                        cout<<"▏   *    ▕"<<"  ";
                    }
                    else if(s[j]==2||s[j]==3){
                        cout<<"▏  * *   ▕"<<"  ";
                    }
                }
                cout <<endl;
                break;
            case 8:
                for(j=begin_r;j<end_r;j++){
                    if(s[j]==1||s[j]==4){
                        cout<<"▏  ***   ▕"<<"  ";
                    }
                    else if(s[j]==2||s[j]==3){
                        cout<<"▏   *    ▕"<<"  ";
                    }
                }
                cout <<endl;
                break;
            case 9:
                for(j=begin_r;j<end_r;j++){
                    cout<<"▏        ▕"<<"  ";
                }
                cout<<endl;
                break;
            case 10:
                for(j=begin_r;j<end_r;j++){
                    if(n[j]>=2&&n[j]<10){
                        cout<<"▏";
                        for(i=0;i<3;i++){
                           cout<<n[j]<<" ";
                        }
                        cout<<n[j]<<" ▕";
                        cout<<"  ";
                    }
                    else if(n[j] == 10){
                        cout<<"▏";
                        for(i=0;i<2;i++){
                            cout<<n[j]<<" ";
                        }
                        cout<<n[j]<<"▕";
                        cout << "  ";
                    }
                    else if(n[j] == 1){
                        cout<<"▏";
                        for(i=0;i<3;i++){
                            cout<<"A ";
                        }
                        cout<<"A"<<" ▕";
                        cout<<"  ";
                    }
                    else if(n[j] == 11){
                        cout<<"▏";
                        for(i=0;i<3;i++){
                            cout<<"J ";
                        }
                        cout<<"J"<<" ▕";
                        cout<<"  ";
                    }
                    else if(n[j] == 12){
                        cout<<"▏";
                        for(i=0;i<3;i++){
                            cout<<"Q ";
                        }
                        cout<<"Q"<<" ▕";
                        cout<<"  ";
                    }
                    else if(n[j] == 13){
                        cout<<"▏";
                        for(i=0;i<3;i++){
                            cout<<"K ";
                        }
                        cout<<"K"<<" ▕";
                        cout<<"  ";
                    }
                }
                cout << endl;
                break;
            case 11:
                for(j=begin_r;j<end_r;j++){
                cout<<"───────────"<<"   ";
                }
                cout << endl;
                break;
            }
        }
        cout<<endl;
        if(k==row-1&&(total%amount)!=0){
            begin_r = begin_r+amount;
            end_r = end_r+(total%amount);
        }
        else{
            begin_r = begin_r+amount;
            end_r = end_r+amount;
        }
    }
    c = c-total;
}
