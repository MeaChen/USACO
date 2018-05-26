/*
ID: mfchen11
TASK: milk
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

struct Node{
    int price;
    int amount;
    //Node(int p, int a): price(p), amount(a){}
};

bool cmp(Node &a, Node b){
    return a.price<b.price;
}
int main(){
    ifstream fin("milk.in");
    ofstream fout("milk.out");
    int total, number;
    fin>>total>>number;
    vector<Node> nodes;
    for(int i=0;i<number;++i){
        Node n;
        fin>>n.price>>n.amount;
        nodes.push_back(n);
    }
    int price=0;
    sort(nodes.begin(),nodes.end(),cmp);
    for(int i=0;i<nodes.size();++i){
        Node nn=nodes[i];
        if(nn.amount<total){
            total-=nn.amount;
            price+=nn.price*nn.amount;
        }else{
            price+=nn.price*total;
            break;
        }
    }
    fout<<price<<endl;
    exit(0);
}