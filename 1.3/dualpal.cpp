/*
ID: mfchen11
TASK: dualpal
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>
using namespace std;

int N;
int S;
string ten2N(int number, int b){
    string result="";
    int x=0;
    while(number>pow(b,x)){
        ++x;
    }
    //cout<<"x: "<<x<<endl;
    if(x==0){
        stringstream stream;
        stream<<number;
        return stream.str();
    }
    while(x>0){
        stringstream ss;
        int base = int(number/pow(b, x-1));
        if(base<10){
            ss<<int(number/pow(b,x-1));
            result+=ss.str();
        }else{
            ss<<char(base-10+97);
            result+=ss.str();
        }
        number = number%int(pow(b,x-1));
        --x;
    }
    return result;
}

bool isPalsquare(string s){
    //int square = number*number;
    
    for(int i=0;i<s.length()/2;++i){
        if(s[i]!=s[s.length()-i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    ifstream fin("dualpal.in");
    ofstream fout("dualpal.out");
    fin>>N;
    fin>>S;
    int total=0;
    int i=S+1;
    while(total<N){
        int number=0;
        for(int base=2;base<=10;++base){
            if(isPalsquare(ten2N(i,base))){
                ++number;
            }
        }
        if(number>=2){
            fout<<i<<endl;
            ++total;
        }
        ++i;
    }
    //cout<<ten2N(120)<<endl;
    //cout<<'A'-65<<endl;
    exit(0);
}