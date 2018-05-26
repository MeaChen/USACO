/*
ID: mfchen11
TASK: skidesign
LANG: C++                 
*/
#include <climits>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <math.h>
#include <set>
using namespace std;

vector<int>hills;
int min_cost(int min_bound){
    int sum=0;
    for(int i=0;i<hills.size();++i){
        if(hills[i]<min_bound)
            sum+=(min_bound-hills[i])*(min_bound-hills[i]);
        else
            break;
    }
    return sum;
}

int max_cost(int max_bound){
    int sum=0;
    for(int i=hills.size()-1;i>=0;--i){
        if(hills[i]>max_bound)
            sum+=(max_bound-hills[i])*(max_bound-hills[i]);
        else
            break;
    }
    return sum;
}

int main(void)
{
    ifstream fin("skidesign.in");
    ofstream fout("skidesign.out");
    
    int N;
    fin>>N;
    
    for(int i=0;i<N;++i){
        int a;
        fin>>a;
        hills.push_back(a);
    }
    sort(hills.begin(),hills.end());
    int dis = hills[hills.size()-1]-hills[0];
    if(dis<=17){
        fout<<0<<endl;
        return 0;
    }
    int min=INT_MAX;
    int diss = dis-17;
    for(int i=0;i<=diss;++i){
        int value = min_cost(hills[0]+i)+max_cost(hills[hills.size()-1]-diss+i);
        if(value<min)
            min=value;
                                                  
    }
    fout<<min<<endl;
    return 0;
}