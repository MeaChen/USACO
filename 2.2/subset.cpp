/*
ID: mfchen11
TASK: subset
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

int N;
unsigned int dp[40+1][2005]={0};

int main(){
    ifstream fin("subset.in");
    ofstream fout("subset.out");
    
    //N=7;
    fin>>N;
    int sum=N*(N+1)/2;
    if(sum%2!=0){
        fout<<"0"<<endl;
        return 0;
    }
    sum=sum/2;
    dp[1][0]=dp[1][1]=1;
    for(int i=2;i<=N;++i){
        for(int j=0;j<=sum;++j){
            if(j<i)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j]+dp[i-1][j-i];
        }
    }
    fout<<dp[N][sum]/2<<endl;
    return 0;

}
