/*
ID: mfchen11
TASK: hamming
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

using namespace std;

int N;   //sets number
int B;   //Bits
int D;  //Distance

bool check(int a, int b)
{
    int k=0;
    while(a||b){
        if(a%2!=b%2)
            ++k;
        a=a/2;
        b=b/2;
    }
    if(k>=D)
        return true;
    else
        return false;
}

int res[64] = {0};
int main(){
    ifstream fin("hamming.in");
    ofstream fout("hamming.out");
    fin>>N>>B>>D;
    int index=1;
    int k=1;
    res[0]=0;
    while(true){
        bool flag=true;
        for(int j=0;j<index;++j){
            if(!check(res[j],k)){
                flag=false;
                break;
            }
        }
        if(flag)
            res[index++]=k;
        if(index>=N)
            break;
        if(k>=(1<<B))
            break;
        ++k;
    }
    for(int i=1;i<index;++i){
        if(i%10==0)
            fout<<res[i-1]<<endl;
        else
            fout<<res[i-1]<<" ";
    }
    //if(index%10==0)
    	fout<<res[index-1]<<endl;
    //else
    //	fout<<res[index-1];
    //fout<<endl;
    return 0;
}
