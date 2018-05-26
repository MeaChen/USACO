/*
ID: mfchen11
TASK: friday
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

bool isLeapYear(int year){
    if(year%100!=0){
        if(year%4==0)
            return true;
    }else{
        if(year%400==0)
            return true;
    }
    return false;
}

int main(){
    ifstream fin("friday.in");
    ofstream fout("friday.out");
    int n;
    fin>>n;
    int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int days2[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    int daysAdded[12]={0};   //sum of the former months
    int daysAdded2[12]={0};
    daysAdded[0]=0;
    daysAdded2[0]=0;
    for(int i=1;i<12;++i){
        daysAdded[i]=daysAdded[i-1]+days[i-1];
        daysAdded2[i]=daysAdded2[i-1]+days2[i-1];
    }
    vector<int>totalDays;   //dates every year
    totalDays.push_back(0);
    int outputs[7]={0};
    vector<int>totalDaysAdded;   //sum of dates
    totalDaysAdded.push_back(0);
    for(int i=1900;i<1900+n;++i){
        int sum = totalDaysAdded[i-1900];
        if(isLeapYear(i)){
            totalDays.push_back(366);
            for(int j=0;j<12;++j){
                int left = sum+daysAdded2[j]+13;
                switch(left%7){
                    case 6:
                        ++outputs[0];
                        break;
                    case 7:
                        ++outputs[1];
                        break;
                    default:
                        ++outputs[left%7+1];
                        break;
                }
            }
            totalDaysAdded.push_back(sum+366);
        }
        else{
            totalDays.push_back(365);
            for(int j=0;j<12;++j){
                int left = sum+daysAdded[j]+13;
                switch(left%7){
                    case 6:
                        ++outputs[0];
                        break;
                    case 7:
                        ++outputs[1];
                        break;
                    default:
                        ++outputs[left%7+1];
                        break;
                }
            }
            totalDaysAdded.push_back(sum+365);
        }
    }
    for(int i=0;i<6;++i){
        fout<<outputs[i]<<" ";
    }
    fout<<outputs[6]<<endl;
    exit(0);
    
}