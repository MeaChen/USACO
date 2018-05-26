/*
ID: mfchen11
TASK: palsquare
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <sstream>
#include <math.h>
using namespace std;


int N;
string ten2N(int number){
    string result="";
    int x=0;
    while(number>pow(N,x)){
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
        int base = int(number/pow(N, x-1));
        if(base<10){
            ss<<int(number/pow(N,x-1));
            result+=ss.str();
        }else{
            ss<<char(base-10+65);
            result+=ss.str();
        }
        number = number%int(pow(N,x-1));
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
    ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");
    //N=10;
    fin>>N;
    for(int i=1;i<=300;++i){
        if(isPalsquare(ten2N(i*i))){
            fout<<ten2N(i)<<" "<<ten2N(i*i)<<endl;
        }
    }
    exit(0);
}