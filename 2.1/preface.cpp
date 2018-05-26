/*
ID: mfchen11
TASK: preface
LANG: C++                 
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <list>
#include <cmath>
#include <fstream>
#define cout fout
using namespace std;

string strs[4][9] = {{"I","II","III","IV","V","VI","VII","VIII","IX"},{"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},{"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"}, {"M","MM","MMM"}};
int N;
int res[7]={0};

int num1=14;
int num2=5;

int main(){
    ifstream fin("preface.in");
    ofstream fout("preface.out");
    
    //N=5;
    fin>>N;
    for(int i=1;i<=N;++i){
        int number=i;
        if(number/1000>0){
            if(i/1000==1)
                res[6]+=1;
            else if(i/1000==2)
                res[6]+=2;
            else if(i/1000==3)
                res[6]+=3;
            number=number%1000;
        }
        if(number/100>0){
            if(number/100==1)
                res[4]+=1;
            else if(number/100==2)
                res[4]+=2;
            else if(number/100==3)
                res[4]+=3;
            else if(number/100==4 || number/100==6){
                res[4]+=1;
                res[5]+=1;
            }else if(number/100==5)
                res[5]+=1;
            else if(number/100==7){
                res[5]+=1;
                res[4]+=2;
            }else if(number/100==8){
                res[5]+=1;
                res[4]+=3;
            }else if(number/100==9){
                res[4]+=1;
                res[6]+=1;
            }
            number=number%100;
        }
        if(number/10>0){
            if(number/10==1)
                res[2]+=1;
            else if(number/10==2)
                res[2]+=2;
            else if(number/10==3)
                res[2]+=3;
            else if(number/10==4 || number/10==6){
                res[2]+=1;
                res[3]+=1;
            }else if(number/10==5)
                res[3]+=1;
            else if(number/10==7){
                res[3]+=1;
                res[2]+=2;
            }else if(number/10==8){
                res[3]+=1;
                res[2]+=3;
            }else if(number/10==9){
                res[2]+=1;
                res[4]+=1;
            }
            number=number%10;
        }
        if(number==1)
            res[0]+=1;
        else if(number==2)
            res[0]+=2;
        else if(number==3)
            res[0]+=3;
        else if(number==4 || number==6){
            res[0]+=1;
            res[1]+=1;
        }else if(number==5)
            res[1]+=1;
        else if(number==7){
            res[1]+=1;
            res[0]+=2;
        }else if(number==8){
            res[1]+=1;
            res[0]+=3;
        }else if(number==9){
            res[0]+=1;
            res[2]+=1;
        }
    }
    if(res[0])
        cout<<"I "<<res[0]<<endl;
    if(res[1])
        cout<<"V "<<res[1]<<endl;

    if(res[2])
        cout<<"X "<<res[2]<<endl;
    if(res[3])
        cout<<"L "<<res[3]<<endl;
    if(res[4])
        cout<<"C "<<res[4]<<endl;
    if(res[5])
        cout<<"D "<<res[5]<<endl;
    if(res[6])
        cout<<"M "<<res[6]<<endl;

    return 0;
}
