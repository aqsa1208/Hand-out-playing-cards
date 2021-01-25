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
        cout<<"�п�J�`�@�n���i��(1~52)(�ثe��"<< c <<"�i)�G";
        cin>>total;
        cout<<endl;
        cout<<"�п�J�C�Ʊi�ơG";
        cin>>amount;
        cout<<endl;
        if(total>c||total<1||amount>total||amount<1){
            cout<<"�п�J�ŦX�d�򪺱i�ơI"<<endl;
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
        cout<<"�ثe�w�L�P�A�O�_�n���s�~�P(1:���s�~�P 2:�����{��)�G";
        cin>>action;
        cout<<endl;
        if(action==1||action==2)
            return action;
        else{
            while(1){
                cout<<"�п�J���T���Ʀr�G";
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
        cout<<"�O�_�n�~��o�P�H(0:�~��o�P 1:���s�~�P 2:�����{��)�G";
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
                cout<<"�п�J���T���Ʀr�G";
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
                cout<<"�w�w�w�w�w�w�w�w�w�w�w"<<"   ";
                }
                cout << endl;
                break;
            case 2:
                for(j=begin_r;j<end_r;j++){
                    if(n[j]>=2&&n[j]<10){
                        cout<<"�j";
                        for(i=0;i<3;i++){
                           cout<<n[j]<<" ";
                        }
                        cout<<n[j]<<" �y";
                        cout<<"  ";
                    }
                    else if(n[j] == 10){
                        cout<<"�j";
                        for(i=0;i<2;i++){
                            cout<<n[j]<<" ";
                        }
                        cout<<n[j]<<"�y";
                        cout << "  ";
                    }
                    else if(n[j] == 1){
                        cout<<"�j";
                        for(i=0;i<3;i++){
                            cout<<"A ";
                        }
                        cout<<"A"<<" �y";
                        cout<<"  ";
                    }
                    else if(n[j] == 11){
                        cout<<"�j";
                        for(i=0;i<3;i++){
                            cout<<"J ";
                        }
                        cout<<"J"<<" �y";
                        cout<<"  ";
                    }
                    else if(n[j] == 12){
                        cout<<"�j";
                        for(i=0;i<3;i++){
                            cout<<"Q ";
                        }
                        cout<<"Q"<<" �y";
                        cout<<"  ";
                    }
                    else if(n[j] == 13){
                        cout<<"�j";
                        for(i=0;i<3;i++){
                            cout<<"K ";
                        }
                        cout<<"K"<<" �y";
                        cout<<"  ";
                    }

                }
                cout << endl;
                break;
            case 3:
                for(j=begin_r;j<end_r;j++){
                    cout<<"�j        �y"<<"  ";
                }
                cout<<endl;
                break;
            case 4:
                for(j=begin_r;j<end_r;j++){
                    if(s[j]==2){
                        cout<<"�j *   *  �y"<<"  ";
                    }
                    else {
                        cout<<"�j   *    �y"<<"  ";
                    }
                }
                cout <<endl;
                break;
            case 5:
                for(j=begin_r;j<end_r;j++){
                    if(s[j]==1){
                        cout<<"�j  * *   �y"<<"  ";
                    }
                    else if(s[j]==2){
                        cout<<"�j*  *  * �y"<<"  ";
                    }
                    else if(s[j]==3){
                        cout<<"�j  * *   �y"<<"  ";
                    }
                    else if(s[j]==4){
                        cout<<"�j* * * * �y"<<"  ";
                    }
                }
                cout <<endl;
                break;
            case 6:
                for(j=begin_r;j<end_r;j++){
                    if(s[j]==1||s[j]==2||s[j]==3){
                        cout<<"�j *   *  �y"<<"  ";
                    }
                    else if(s[j]==4){
                        cout<<"�j * * *  �y"<<"  ";
                    }
                }
                cout <<endl;
                break;
            case 7:
                for(j=begin_r;j<end_r;j++){
                    if(s[j]==1||s[j]==4){
                        cout<<"�j   *    �y"<<"  ";
                    }
                    else if(s[j]==2||s[j]==3){
                        cout<<"�j  * *   �y"<<"  ";
                    }
                }
                cout <<endl;
                break;
            case 8:
                for(j=begin_r;j<end_r;j++){
                    if(s[j]==1||s[j]==4){
                        cout<<"�j  ***   �y"<<"  ";
                    }
                    else if(s[j]==2||s[j]==3){
                        cout<<"�j   *    �y"<<"  ";
                    }
                }
                cout <<endl;
                break;
            case 9:
                for(j=begin_r;j<end_r;j++){
                    cout<<"�j        �y"<<"  ";
                }
                cout<<endl;
                break;
            case 10:
                for(j=begin_r;j<end_r;j++){
                    if(n[j]>=2&&n[j]<10){
                        cout<<"�j";
                        for(i=0;i<3;i++){
                           cout<<n[j]<<" ";
                        }
                        cout<<n[j]<<" �y";
                        cout<<"  ";
                    }
                    else if(n[j] == 10){
                        cout<<"�j";
                        for(i=0;i<2;i++){
                            cout<<n[j]<<" ";
                        }
                        cout<<n[j]<<"�y";
                        cout << "  ";
                    }
                    else if(n[j] == 1){
                        cout<<"�j";
                        for(i=0;i<3;i++){
                            cout<<"A ";
                        }
                        cout<<"A"<<" �y";
                        cout<<"  ";
                    }
                    else if(n[j] == 11){
                        cout<<"�j";
                        for(i=0;i<3;i++){
                            cout<<"J ";
                        }
                        cout<<"J"<<" �y";
                        cout<<"  ";
                    }
                    else if(n[j] == 12){
                        cout<<"�j";
                        for(i=0;i<3;i++){
                            cout<<"Q ";
                        }
                        cout<<"Q"<<" �y";
                        cout<<"  ";
                    }
                    else if(n[j] == 13){
                        cout<<"�j";
                        for(i=0;i<3;i++){
                            cout<<"K ";
                        }
                        cout<<"K"<<" �y";
                        cout<<"  ";
                    }
                }
                cout << endl;
                break;
            case 11:
                for(j=begin_r;j<end_r;j++){
                cout<<"�w�w�w�w�w�w�w�w�w�w�w"<<"   ";
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
