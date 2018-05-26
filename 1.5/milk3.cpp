/*
ID: mfchen11
TASK: milk3
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <cstdio>
using namespace std;

int A,B,C;
int milk[21][21][21];
int note[21]={0};

void DFS(int a, int b, int c){
    if(milk[a][b][c]==1)
        return;
    milk[a][b][c]=1;
    if(a==0)
        note[c]=1;
    
    //A to B
    if(a+b>=B){
        DFS(a+b-B, B, c);
    }else{
        DFS(0, a+b, c);
    }
    
    //A to C
    if(a+c>=C){
        DFS(a+c-C, b, C);
    }else{
        DFS(0, b, a+c);
    }
    
    //B to A
    if(a+b>=A){
        DFS(A, a+b-A, c);
    }else{
        DFS(a+b, 0, c);
    }
    
    //B to C
    if(b+c>=C){
        DFS(a, b+c-C, C);
    }else{
        DFS(a, 0, b+c);
    }
    
    //C to A
    if(a+c>=A){
        DFS(A, b, a+c-A);
    }else{
        DFS(a+c, b, 0);
    }
    
    //C to B
    if(b+c>=B){
        DFS(a, B, b+c-B);
    }else{
        DFS(a, b+c, 0);
    }
}
int main(void)
{
    ifstream fin("milk3.in");
    ofstream fout("milk3.out");
    
    memset(milk, 0, sizeof(milk));
    //A=2, B=5, C=10;
    fin>>A>>B>>C;
    DFS(0,0,C);
    //bool flag=true;
    int ans[21]={0};
    int index=0;
    for(int i=0;i<21;++i){
        if(note[i]==1){
            ans[index++]=i;
        }
    }
    for(int i=0;i<index-1;++i){
        fout<<ans[i]<<" ";
    }
    fout<<ans[index-1]<<endl;
    return 0;
}