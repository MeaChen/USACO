/*
ID: mfchen11
TASK: runround
LANG: C++                 
*/

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>

using namespace std;

bool isRound(int x){
    int numbers[10]={0};
    stringstream ss;
    ss<<x;
    string input=ss.str();
    int i=0;
    int length=input.length();
    for(i=0;i<length;++i){
        numbers[input[i]-'0']++;
    }
    if(numbers[0]!=0)
        return false;
    for(i=1;i<=9;++i)
        if(numbers[i]>1)
            return false;
    int next_i = 0;
    int visited[10]={0};
    int round_number=0;
    do{
    	round_number++;
        if(round_number>length)
            return false;
        int nnn = (input[next_i]-'0')%length;
        int next_ii = next_i+nnn;
        if(next_ii>=length)
            next_ii -= length;
        next_i=next_ii;
        visited[next_i]=1;
    }while(next_i!=0);
    for(i=1;i<length;++i){
        if(visited[i]==0)
            return false;
    }
    return true;
}

int main(){
    ifstream fin("runround.in");
    ofstream fout("runround.out");
    //cout<<"start"<<endl;
    int x;
    fin>>x;
    x+=1;
    while(1){
        if(isRound(x)){
            fout<<x<<endl;
            return 0;
        }
        x++;
    }
    return 0;
}
