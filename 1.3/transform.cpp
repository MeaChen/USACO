/*
ID: mfchen11
TASK: transform
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define maxn 12
#define cout fout

int N;
char temp[maxn][maxn];
char ori[maxn][maxn];
char tar[maxn][maxn];

bool isSame(){
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(temp[i][j]!=tar[i][j])
                return false;
        }
    }
    return true;
}


void rotate(){
    char tmp[12][12] ;
    for( int i = 0 ; i < N ; i ++ )
        for( int j = 0 ; j < N ; j ++ )
            tmp[j][N-1-i] = temp[i][j] ;
    for( int i = 0 ; i < N ; i ++ ){
        for( int j = 0 ; j < N ; j ++ ){
            temp[i][j] = tmp[i][j];
            //cout<<temp[i][j]<<" ";
        }
        //cout<<endl;
    }
}

void reflect(){
    char tmp[12][12] ;
    for( int i = 0 ; i < N ; i ++ )
        for( int j = 0 ; j < N ; j ++ )
            tmp[i][N-1-j] = temp[i][j] ;
    for( int i = 0 ; i < N ; i ++ )
        for( int j = 0 ; j < N ; j ++ )
            temp[i][j] = tmp[i][j];
}

int main(){
    ifstream fin("transform.in");
    ofstream fout("transform.out");
    fin>>N;
    //char copy[maxn][maxn];
    //char copy2[maxn][maxn];
    
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            char x;
            fin>>x;
            ori[i][j]=x;
            temp[i][j]=x;
            //cout<<x<<" ";
            //copy[i][j]=x;
            //copy2[i][j]=x;
        }
        //cout<<endl;
    }
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            char x;
            fin>>x;
            tar[i][j]=x;
        }
    }
    rotate();
    if(isSame()){
        cout<<"1"<<endl;
        exit(0);
    }
    rotate();
    if(isSame()){
        cout<<"2"<<endl;
        exit(0);
    }
    rotate();
    if(isSame()){
        cout<<"3"<<endl;
        exit(0);
    }
    for( int i = 0 ; i < N ; i ++ )
        for( int j = 0 ; j < N ; j ++ )
            temp[i][j] = ori[i][j];
    reflect();
    if(isSame()){
        cout<<"4"<<endl;
        exit(0);
    }
    rotate();
    if(isSame()){
        cout<<"5"<<endl;
        exit(0);
    }
    rotate();
    if(isSame()){
        cout<<"5"<<endl;
        exit(0);
    }
    rotate();
    if(isSame()){
        cout<<"5"<<endl;
        exit(0);
    }
    for( int i = 0 ; i < N ; i ++ )
        for( int j = 0 ; j < N ; j ++ )
            temp[i][j] = ori[i][j];
    if(isSame()){
        cout<<"6"<<endl;
        exit(0);
    }
    cout<<"7"<<endl;
    exit(0);
}