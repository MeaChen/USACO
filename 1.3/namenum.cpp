/*
ID: mfchen11
TASK: namenum
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <sstream>
using namespace std;
#define cout fout

int main(){
    ifstream fin("namenum.in");
    ofstream fout("namenum.out");
    string str;
    fin>>str;
    
    int table2[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};
    ifstream findict("dict.txt");
    string sss;
    int flag=0;
    //set<string> dicts;
    while(findict>>sss){
        string expected="";
        for(int i=0;i<sss.length();++i){
            if(table2[sss[i]-'A']!=0){
                stringstream ss;
                ss<<table2[sss[i]-'A'];
                expected+=ss.str();
            }
        }
        if(expected==str){
            cout<<sss<<endl;
            flag=1;
        }
    }
    if(flag==0){
        cout<<"NONE"<<endl;
    }
    
    exit(0);
}