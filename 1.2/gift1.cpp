/*
ID: mfchen11
TASK: gift1
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");
    string str;
    vector<int> ends;
    vector<string> members;
    map<string, int> name2number;
    fin>>str;
    int number = atoi(str.c_str());
    for(int i=0;i<number;++i){
        fin>>str;
        name2number[str]=i;
        ends.push_back(0);
        members.push_back(str);
    }
    while(fin>>str){
        int index = name2number[str];
        int amount, givingNo;
        fin>>amount>>givingNo;
        //int average, left;
        if(givingNo==0){
            //ends[index]+=amount;
            continue;
        }
        int average = int(amount/givingNo);
        int left = amount%givingNo;
        for(int i=0;i<givingNo;++i){
            fin>>str;
            ends[name2number[str]]+=average;
        }
        ends[index]+=(left-amount);
    }
    for(int i=0;i<number;++i){
        fout<<members[i]<<" "<<ends[i]<<endl;
    }
    
    exit(0);
    
    
    
}