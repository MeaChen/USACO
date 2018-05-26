/*
ID: mfchen11
TASK: beads
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
    ifstream fin("beads.in");
    ofstream fout("beads.out");
    int n;
    fin>>n;
    string str;
    fin>>str;
    //string str="wwwbbrwrbrbrrbrbrwrwwrbwrwrrb";
    string str2=str;
    str+=str2;

    int max=0;
    for(int i=1;i<=n;++i){
        char former = str[i-1];
        char later = str[i];
        int j;
        int k;
        if(former!='w'){
            j=i-1;
        }else{
            j=i-1;
            while(str[j]=='w' && j>=0){
                --j;
            }
            former=str[j];
        }
        if(later!='w'){
            k=i;
        }else{
            k=i;
            while(str[k]=='w' && k<str.length()){
                ++k;
            }
            later=str[k];
        }
        while(j>=0){
            if(str[j]==former || str[j]=='w'){
                --j;
            }
            else{
                break;
            }
        }
        while(k<str.length()){
            if(str[k]==later || str[k]=='w'){
                ++k;
            }else{
                break;
            }
        }
        int total = k-j-1;
        if(total>max){
            max=total;
        }
    }
    if(max>n)
    	fout<<n<<endl;
    else
    	fout<<max<<endl;
    exit(0);
    
}