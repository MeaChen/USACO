/*
ID: mfchen11
TASK: pprime
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <math.h>
#include <vector>
using namespace std;

vector <int> oddPalindromeList;
void oneDigit ()
{
    for ( int i = 1; i <= 9; i += 2 ) oddPalindromeList.push_back (i);
}

void twoDigit ()
{
    for ( int i = 1; i <= 9; i += 2 ) oddPalindromeList.push_back (i * 10 + i);
}

void threeDigit ()
{
    for ( int i = 1; i <= 9; i += 2 ) {
        for ( int j = 0; j <= 9; j++ )
            oddPalindromeList.push_back (100 * i + 10 * j + i);
    }
}

void fourDigit ()
{
    for ( int i = 1; i <= 9; i += 2 ) {
        for ( int j = 0; j <= 9; j++ )
            oddPalindromeList.push_back (1000 * i + 100 * j + 10 * j + i);
    }
}

void fiveDigit ()
{
    for ( int i = 1; i <= 9; i += 2 ) {
        for ( int j = 0; j <= 9; j++ ) {
            for ( int k = 0; k <= 9; k++ )
                oddPalindromeList.push_back (10000 * i + 1000 * j + 100 * k + 10 * j + i);
        }
    }
}

void sixDigit ()
{
    for ( int i = 1; i <= 9; i += 2 ) {
        for ( int j = 0; j <= 9; j++ ) {
            for ( int k = 0; k <= 9; k++ )
                oddPalindromeList.push_back (100000 * i + 10000 * j + 1000 * k + 100 * k + 10 * j + i);
        }
    }
}

void sevenDigit ()
{
    for ( int i = 1; i <= 9; i += 2 ) {
        for ( int j = 0; j <= 9; j++ ) {
            for ( int k = 0; k <= 9; k++ ) {
                for ( int l = 0; l <= 9; l++ )
                    oddPalindromeList.push_back (1000000 * i + 100000 * j + 10000 * k + 1000 * l + 100 * k + 10 * j + i);
            }
        }
    }
}

void eightDigit ()
{
    for ( int i = 1; i <= 9; i += 2 ) {
        for ( int j = 0; j <= 9; j++ ) {
            for ( int k = 0; k <= 9; k++ ) {
                for ( int l = 0; l <= 9; l++ )
                    oddPalindromeList.push_back (10000000 * i + 1000000 * j + 100000 * k + 10000 * l + 1000 * l + 100 * k + 10 * j + i);
            }
        }
    }
}

void generatePalinDrome ()
{
    oneDigit ();
    twoDigit ();
    threeDigit ();
    fourDigit ();
    fiveDigit ();
    sixDigit ();
    sevenDigit ();
    eightDigit ();
}

int a,b;
bool isPrime(int number){
    bool flag=true;
    for(int i=2;i*i<=number;++i){
        if(number%i==0){
            flag=false;
            break;
        }
    }
    return flag;
}


int main(void)
{
    ifstream fin("pprime.in");
    ofstream fout("pprime.out");
    
    //a=5, b=500;
    fin>>a>>b;
    generatePalinDrome();
    for(int i=0;i<oddPalindromeList.size();++i){
        if(oddPalindromeList[i]>=a && oddPalindromeList[i]<=b && isPrime(oddPalindromeList[i]))
            fout<<oddPalindromeList[i]<<endl;
    }
    return 0;
}