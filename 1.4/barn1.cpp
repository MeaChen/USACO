/*
ID: mfchen11
TASK: barn1
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <math.h>
using namespace std;

int main(){
    ifstream fin("barn1.in");
    ofstream fout("barn1.out");
    int M, S, C;
    fin>>M>>S>>C;
    vector<int> gaps;
    int number;
    
    vector<int> numbers;
    for(int i=0;i<C;++i){
        fin>>number;
        numbers.push_back(number);
    }

    sort(numbers.begin(), numbers.end());
    int min = numbers[0];
    int max = numbers[numbers.size()-1];
    
    for(int i=1;i<numbers.size();++i){
    	if(numbers[i]-numbers[i-1]!=1)
    		gaps.push_back(numbers[i]-numbers[i-1]);
    }
    sort(gaps.begin(), gaps.end(), greater<int>());
    int sum=0;
    int size = M-1<gaps.size() ? M-1:gaps.size();
    for(int i=0;i<size;++i){
        sum+=gaps[i]-1;
    }
    fout<<max-min+1-sum<<endl;
    exit(0);
}