/*
ID: mfchen11
TASK: sprime
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <math.h>
#include <vector>
using namespace std;
#define MAX_N 100000

int sp[8][MAX_N] = {0};
int length[8]={0};

bool isPrime(int number){
    if(number==1)
        return false;
    bool flag=true;
    for(int i=2;i*i<=number;++i){
        if(number%i==0){
            flag=false;
            break;
        }
    }
    return flag;
}

int main(void)
{
    ifstream fin("sprime.in");
    ofstream fout("sprime.out");
    int N;
    fin>>N;
    memset(sp,0,sizeof(sp));
    memset(length,0,sizeof(length));
    //N=4;
    if(N==1){
        cout<<2<<endl<<3<<endl<<5<<endl<<7<<endl;
        return 0;
    }
    sp[0][0]=2;
    sp[0][1]=3;
    sp[0][2]=5;
    sp[0][3]=7;
    length[0]=4;
    //cout<<isSuperPrime(2333)<<endl;
    for(int i=1;i<N;++i){
        int index=0;
        for(int k=0;k<length[i-1];++k){
            if(isPrime(sp[i-1][k]*10+1))
                sp[i][index++] = sp[i-1][k]*10+1;
            if(isPrime(sp[i-1][k]*10+3))
                sp[i][index++] = sp[i-1][k]*10+3;
            if(isPrime(sp[i-1][k]*10+7))
                sp[i][index++] = sp[i-1][k]*10+7;
            if(isPrime(sp[i-1][k]*10+9))
                sp[i][index++] = sp[i-1][k]*10+9;
        }
        length[i]=index;
    }
    for(int i=0;i<length[N-1];++i)
        fout<<sp[N-1][i]<<endl;
    return 0;
}
