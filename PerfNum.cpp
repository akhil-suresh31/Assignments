/*
    Author: Akhil Suresh
    q:given n find tall perfect no. between 1-n 

*/
#include<iostream>
using namespace std;

void perfno(int n)
{
    for(int i=1;i<=n;i++)
    {
        int j = i/2, sum=0;
        while(j)
        {
            if( i % j == 0)
                sum+=j;
            j--;
        }
        if(sum == i)
            cout<<i<<",";
    }
}

int main(int argc, char const *argv[])
{
    int n;
    do{
    cout<<"Enter the value of n(n>0):";
    cin>>n;
    }while(n<0);
    cout<<"perfect no. between 1-n are:";
    perfno(n);
    return 0;
}
