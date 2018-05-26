/*
ID: mfchen11
TASK: ride
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	ifstream fin("ride.in");
	ofstream fout("ride.out");
	string a, b;
	fin>>a>>b;
	int sum_a=1, sum_b=1;
	//a = "COMETQ";
    //b = "HVNGAT";
	for(int i=0;i<a.length();++i){
		sum_a *= int(a[i])-int('A')+1;
	}
	for(int i=0;i<b.length();++i){
		sum_b *= int(b[i])-int('A')+1;
	}

	if(sum_a%47==sum_b%47){
		fout<<"GO"<<endl;
	}else{
		fout<<"STAY"<<endl;
	}

	exit(0);
}