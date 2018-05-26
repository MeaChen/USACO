/*
ID: mfchen11
TASK: milk2
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval{
    int start;
    int end;
};

bool compare(Interval a, Interval b){
    return a.start<b.start;
}

int main(){
    ifstream fin("milk2.in");
    ofstream fout("milk2.out");
    int n;
    fin>>n;
    if(n==0)
        exit(0);
    int start,end;
    vector<Interval> data;
    for(int i=0;i<n;++i){
        fin>>start>>end;
        Interval in;
        in.start=start;
        in.end=end;
        data.push_back(in);
    }
    sort(data.begin(), data.end(), compare);
    int first = data[0].start;
    int last = data[0].end;
    int maxInterval = last-first;
    int maxGap = 0;
    for(int i=1;i<data.size();++i){
        //cout<<data[i].start<<" "<<data[i].end<<endl;
        Interval inter = data[i];
        if(inter.start<=last){
            last = inter.end<last ? last:inter.end;
        }else{
            if(last-first>maxInterval){
                maxInterval=last-first;
            }

            if(inter.start-last>maxGap){
                maxGap=inter.start-last;
            }
            first = inter.start;
            last = inter.end;
        }
    }
    fout<<maxInterval<<" "<<maxGap<<endl;
    exit(0);
}