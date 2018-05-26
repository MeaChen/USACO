/*
ID: mfchen11
TASK: sort3
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
#define MAX_N 1000


int lst[MAX_N] = {0};

int main(void)
{
    ifstream fin("sort3.in");
    //ifstream fin("frac1.in");
    ofstream fout("sort3.out");
    
    int N;
    fin>>N;
    
    int ones=0, twos=0, threes=0;
    for(int i=0;i<N;++i){
        fin>>lst[i];
        if(lst[i]==1)
            ones++;
        else if(lst[i]==2)
            twos++;
        else
            threes++;
    }
    //cout<<ones<<" "<<twos<<" "<<threes<<endl;
    
    int cnt=0;

    //int no_one=0;
    int one_in_two=0;
    int one_in_three=0;
    int three_in_one=0;
    int three_in_two=0;
    int two_in_one=0;
    int two_in_three=0;
    int old_One=0;
    for(int i=0;i<ones;++i){
        if(lst[i]==3)
            three_in_one++;
        else if(lst[i]==2)
            two_in_one++;
        else
            old_One++;
    }
    for(int i=ones;i<twos+ones;++i){
        if(lst[i]==1){
            one_in_two++;
            //no_two++;
        }
        else if(lst[i]==3)
            three_in_two++;
    }

    for(int i=twos+ones;i<N;++i){
        if(lst[i]==1)
            one_in_three++;
        else if(lst[i]==2)
            two_in_three++;
    }
    cnt = min(one_in_two,two_in_one) + min(one_in_three, three_in_one) + min(two_in_three, three_in_two);
    //cout<<no_one<<" "<<one_in_two<<" "<<one_in_three<<endl;
    cnt+=(ones-old_One-min(one_in_two,two_in_one)-min(one_in_three, three_in_one))*2;
    fout<<cnt<<endl;
    return 0;
}
