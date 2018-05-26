/*
ID: mfchen11
TASK: frac1
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
#define MAX_N 160
#define cout fout

struct Frac{
    int numerator;
    int denumerator;
};

bool cmp(Frac a, Frac b){
    //return float(a.numerator/a.denumerator) < float(b.numerator/b.denumerator);
    return a.numerator*b.denumerator < a.denumerator*b.numerator;
}

int gcd(int x, int y){
    if(y==0)
        return x;
    return gcd(y, x%y);
}

vector<Frac> lst;
int hash_[MAX_N+1][MAX_N+1] = {0};

int main(void)
{
    //ifstream fin("/Users/mufan/hello/hello/numtri.in");
    ifstream fin("frac1.in");
    ofstream fout("frac1.out");
    
    int N;
    fin>>N;
    if(N>1){
        for(int i=N;i>=2;--i){
            for(int j=1;j<i;++j){
                //cout<<j<<" "<<i<<endl;
                int GCD = gcd(i,j);
                int m=i, n=j;
                if(GCD!=1){
                    m=i/GCD;
                    n=j/GCD;
                }
                if(hash_[m][n]==0){
                    Frac f;
                    f.numerator = n;
                    f.denumerator = m;
                    lst.push_back(f);
                    hash_[m][n]=1;
                }
            }
        }
    }else{
        cout<<"0/1"<<endl;
        cout<<"1/1"<<endl;
        return 0;
    }
    cout<<"0/1"<<endl;
    sort(lst.begin(), lst.end(), cmp);
    for(int i=0;i<lst.size();++i){
        cout<<lst[i].numerator<<"/"<<lst[i].denumerator<<endl;
    }
    cout<<"1/1"<<endl;
    return 0;
}