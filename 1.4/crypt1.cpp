/*
ID: mfchen11
TASK: crypt1
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

int main(){
    ifstream fin("crypt1.in");
    ofstream fout("crypt1.out");
    
    int no;
    fin>>no;
    set<int> numbers;
    vector<int> vec_numbers;
    for(int i=0;i<no;++i){
        int number;
        fin>>number;
        numbers.insert(number);
        vec_numbers.push_back(number);
    }
    vector<int>threes;
    vector<int>twos;
    for(int i=0;i<no;++i){
    	if(vec_numbers[i]==0)
            continue;
        for(int j=0;j<no;++j){
            twos.push_back(vec_numbers[i]*10+vec_numbers[j]);
            for(int k=0;k<no;++k){
                threes.push_back(vec_numbers[i]*100+vec_numbers[j]*10+vec_numbers[k]);
            }
        }
    }
    int total=0;
    for(int i=0;i<threes.size();++i){
        for(int j=0;j<twos.size();++j){
            int flag=0;
            int first = threes[i]*(twos[j]%10);
            stringstream ss;
            ss<<first;
            string firsts = ss.str();
            if(firsts.length()!=3){
                flag=1;
                continue;
            }
            for(int m=0;m<firsts.length();++m){
                if(numbers.count(firsts[m]-'0')==0){
                    flag=1;
                    break;
                }
            }
            //cout<<"flag1: "<<flag<<endl;
            if(flag==0){
                int second = threes[i]*int(twos[j]/10);
                stringstream xx;
                xx<<second;
                string seconds = xx.str();
                if(seconds.length()!=3){
                    flag=1;
                    continue;
                }
                for(int n=0;n<seconds.length();++n){
                    if(numbers.count(seconds[n]-'0')==0){
                        flag=1;
                        break;
                    }
                }
            }
            //cout<<"flag2: "<<flag<<endl;
            if(flag==0){
                stringstream tt;
                tt<<threes[i]*twos[j];
                string all = tt.str();
                //cout<<all<<endl;
                if(all.length()!=4){
                    flag=1;
                    continue;
                }
                for(int g=0;g<all.length();++g){
                    if(numbers.count(all[g]-'0')==0){
                        flag=1;
                        break;
                    }
                }
            }
            //cout<<"flag3: "<<flag<<endl;
            if(flag==0){
                //cout<<threes[i]<< " x "<<twos[j]<<endl;
                ++total;
            }
        }
    }
    fout<<total<<endl;
    exit(0);
}