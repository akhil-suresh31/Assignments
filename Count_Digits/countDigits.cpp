/*
    Author: Akhil Suresh
    q: Program to count the no. of digits
*/
#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int num,count=0;
    cout<<"Enter the number to count the no. of digits:";
    cin>>num;
    int temp=num;
    if(num == 0)
        count=1;
    while(temp)
    {
        count++;
        temp/=10;
    }
    cout<<num<<" has "<<count<<" digits";
    return 0;
}
