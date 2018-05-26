/*
ID: mfchen11
TASK: holstein
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

#define MAXV 26
#define MAXG 16
#define INF 327699


//gobal variable====
int V;
int requirement[MAXV];
int G;
int feed[MAXG][MAXV];
int result;

int ans[MAXG];
int vit[MAXV];
int res[MAXG];
//==================


//function==========
bool check(){
    bool flag = true;
    for(int i = 0; i < V; i++){
        if(vit[i] < requirement[i])
            flag = false;
    }
    return flag;
}

void DFS(int deep, int count){
    if(deep == G){
        if(check() == false)
            return;
        if(count < result){
            result = count;
            for(int i = 0; i < result; i++){
                res[i] = ans[i];
            }
        }
        return;
    }
    for(int i = 0; i < V; i++){
        vit[i] += feed[deep][i];
    }
    ans[count] = deep;
    DFS(deep + 1, count + 1);
    for(int i = 0; i < V; i++){
        vit[i] -= feed[deep][i];
    }
    DFS(deep + 1, count);
    return;
}

//==================

int main(){
    ifstream fin("holstein.in");
    ofstream fout("holstein.out");
    fin>>V;
    for(int i = 0; i < V; i++){
        fin>>requirement[i];
    }
    fin>>G;
    for(int i = 0; i < G; i++){
        for(int j = 0; j < V; j++){
            fin>>feed[i][j];
        }
    }
    memset(res, 0, sizeof(res));
    memset(ans, 0, sizeof(ans));
    memset(vit, 0, sizeof(vit));
    result = INF;
    DFS(0, 0);
    fout<<result;
    for(int i = 0; i < result; i++){
        fout<<" "<<res[i]+1;
    }
    fout<<endl;
    return 0;
}