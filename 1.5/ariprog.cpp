/*
ID: mfchen11
TASK: ariprog
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <math.h>
#include <set>
using namespace std;

#define MAX_N 125000

int squares[MAX_N+1]={0};

int main(void)
{
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");
    
    int N;
    int M;
    fin>>N>>M;
    for(int i=0; i<=M; i++)
        for(int j=i; j<=M; j++)
            squares[i*i+j*j]=1;
    int next[MAX_N+1] = {0};
    int index=0;
    for(int i=0;i<=M*M*2;++i){
        if(squares[i]==1){
            next[index]=i;
            ++index;
        }
    }
    
    vector<pair<int, int> > results;
    for(int i = 0; i < index; ++i)
        for(int j=i+1; j < index; ++j){
            int dis = next[j] - next[i];
            bool flag = true;
            int k;
            for(k=3; k<=N; ++k){
                if(next[j]+(k-2)*dis>125000||squares[next[j]+(k-2)*dis]==0){
                    flag = false;
                    break;
                }
            }
            if(flag&&k==N+1){
                results.push_back(make_pair(dis,next[i]));
            }

        }
    
    
    sort(results.begin(), results.end());
    if(results.size()==0){
        fout<<"NONE"<<endl;
    }else{
        for(int i=0;i<results.size();++i){
            fout<<results[i].second<<" "<<results[i].first<<endl;
        }
    }
    
    return 0;
}