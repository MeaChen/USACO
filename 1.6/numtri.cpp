/*
ID: mfchen11
TASK: numtri
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>
#include <sstream>
using namespace std;

int N;
int tri[1000][1000];
int dp[1000+1][1000+1];

int main(void)
{
    ifstream fin("numtri.in");
    ofstream fout("numtri.out");
    
    memset(tri, 0, sizeof(tri));
    memset(dp, 0, sizeof(dp));
    fin>>N;
    for(int i=0;i<N;++i){
        for(int j=0;j<i+1;++j){
            fin>>tri[i][j];
        }
    }
    
    //dp[0][0]=tri[0][0];
    for(int i=1;i<N+1;++i){
        for(int j=0;j<i+1;++j){
            if(j==0){
                dp[i][j] = tri[i-1][j]+dp[i-1][j];
            }else if(j==i){
                dp[i][j] = tri[i-1][j-1]+dp[i-1][j-1];
            }else{
                dp[i][j] = max(tri[i-1][j-1]+dp[i-1][j-1], tri[i-1][j]+dp[i-1][j]);
            }
        }
    }
    int max=0;
    for(int i=0;i<N;++i){
        if(dp[N][i]>max)
            max=dp[N][i];
    }
    fout<<max<<endl;
    return 0;
}