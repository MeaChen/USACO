/*
ID: mfchen11
TASK: wormhole
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

#define MAX_N 12

int N, X[MAX_N+1], Y[MAX_N+1];
int wife[MAX_N+1];
int next_on_right[MAX_N+1];

bool cycle_exists(void)
{
    for (int start=1; start<=N; start++)
    {
        int pos = start;
        for (int count=0; count<N; count++)
            pos = next_on_right[wife[pos]];
        if (pos != 0) return true;
    }
    return false;
}

int solve(void)
{
    int i, total=0;
    for (i=1; i<=N; i++)
        if (wife[i] == 0)
            break;
    
    // everyone paired?
    if (i > N)
    {
        if (cycle_exists()) return 1;
        else return 0;
    }
    
    for (int j=i+1; j<=N; j++)
        if (wife[j] == 0)
        {
            wife[i] = j;
            wife[j] = i;
            total += solve();
            wife[i] = wife[j] = 0;
        }
    return total;
}

int main(void)
{
    ifstream fin("wormhole.in");
    fin >> N;
    for (int i=1; i<=N; i++) fin >> X[i] >> Y[i];
    fin.close();
    
    for (int i=1; i<=N; i++) // set next_on_right[i]...
        for (int j=1; j<=N; j++)
            if (X[j] > X[i] && Y[i] == Y[j]) // j right of i...
                if (next_on_right[i] == 0 ||
                    X[j]-X[i] < X[next_on_right[i]]-X[i])
                    next_on_right[i] = j;
    
    ofstream fout("wormhole.out");
    fout << solve() << endl;
    fout.close();
    return 0;
}