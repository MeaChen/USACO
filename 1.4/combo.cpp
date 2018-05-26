/*
ID: mfchen11
TASK: combo
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

int N;
int dis(int a, int b){
    int x=abs(a-b);

    return (x<=4?5-x:0)+(N-4<=x?5-N+x:0);
}

int main(){
    ifstream fin("combo.in");
    ofstream fout("combo.out");
    //int N;
    fin>>N;
    if(N<=5){
        fout<<N*N*N<<endl;
    }
    else{
        int a1,b1,c1;
        int a2,b2,c2;
        fin>>a1>>b1>>c1;
        fin>>a2>>b2>>c2;
        //cout<<a1<<" "<<b1<<" "<<c1<<endl;
        int d1=dis(a1,a2);
        
        int d2=dis(b1,b2);
        int d3=dis(c1,c2);
        //cout<<d1<<" "<<d2<<" "<<d3<<endl;
        fout<<250-d1*d2*d3<<endl;
    }
    
    exit(0);
}
