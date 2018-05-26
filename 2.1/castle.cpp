/*
ID: mfchen11
TASK: castle
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;

struct Square{
    int x,y;
    bool visited;
    bool walls[4];
    int color;
    int area;
};

int colors=0;
int main(void)
{
    ifstream fin("castle.in");
    ofstream fout("castle.out");
    int M, N;
    fin>>M>>N;
    //vector<Square>space;
    Square **space = new Square* [N];
    for(int i=0;i<N;++i){
        space[i] = new Square[M];
    }
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            int number;
            fin>>number;
            Square s;
            if(number>=8){
                s.walls[3]=1;
                number-=8;
            }else
                s.walls[3]=0;
            if(number>=4){
                s.walls[2]=1;
                number-=4;
            }else
                s.walls[2]=0;
            if(number>=2){
                s.walls[1]=1;
                number-=2;
            }else
                s.walls[1]=0;
            s.walls[0]=number;
            s.x=i;
            s.y=j;
            space[i][j]=s;
        }
    }
    int max_area=0;
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            Square curr = space[i][j];
            if(curr.visited==0){
                ++colors;
                queue<Square> q;
                queue<Square> pp;
                space[i][j].visited=1;
                q.push(curr);
                pp.push(curr);
                while(!q.empty()){
                    Square sq = q.front();
                    q.pop();
                    //sq.visited=1;
                    if(sq.walls[1]==0 && sq.x-1>=0 && space[sq.x-1][sq.y].visited==0){
                        Square north = space[sq.x-1][sq.y];
                        space[sq.x-1][sq.y].visited=1;
                        q.push(north);
                        pp.push(north);
                    }
                    if(sq.walls[0]==0 && sq.y-1>=0 && space[sq.x][sq.y-1].visited==0){
                        Square west = space[sq.x][sq.y-1];
                        space[sq.x][sq.y-1].visited=1;
                        pp.push(west);
                        q.push(west);
                    }
                    if(sq.walls[2]==0 && sq.y+1<M && space[sq.x][sq.y+1].visited==0){
                        Square east = space[sq.x][sq.y+1];
                        space[sq.x][sq.y+1].visited=1;
                        pp.push(east);
                        q.push(east);
                    }
                    if(sq.walls[3]==0 && sq.x+1<N && space[sq.x+1][sq.y].visited==0){
                        Square south = space[sq.x+1][sq.y];
                        space[sq.x+1][sq.y].visited=1;
                        pp.push(south);
                        q.push(south);
                    }
                }
                
                int area = pp.size();
                if(area>max_area)
                    max_area=area;
                while(!pp.empty()){
                    Square x=pp.front(); pp.pop();
                    space[x.x][x.y].color=colors;
                    space[x.x][x.y].area=area;
                }
            }
        }
    }
    fout<<colors<<endl;
    fout<<max_area<<endl;
    char dir;
    int max_x, max_y, max_a;
    for(int y=0;y<M;++y)
        for(int x=N-1;x>=0;--x){
            if(x>0 && space[x][y].color!=space[x-1][y].color){
                if(space[x][y].area+space[x-1][y].area>max_a){
                    max_a = space[x][y].area+space[x-1][y].area;
                    max_x = x;
                    max_y = y;
                    dir = 'N';
                }
            }
            if(y<M-1 && space[x][y].color !=space[x][y+1].color){
                if(space[x][y].area + space[x][y+1].area > max_a){
                    max_a = space[x][y].area + space[x][y+1].area;
                    max_y = y;
                    max_x = x;
                    dir = 'E';
                }
                
            }
        }
    fout<<max_a<<endl;
    fout<<max_x+1<<" "<<max_y+1<<" "<<dir<<endl;
    return 0;
}
