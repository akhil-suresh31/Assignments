/*
    Author: Akhil Suresh
    q: Program to count the no. of digits
*/
#include<iostream>
#include"CountDigits.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    int num,count;
    cout<<"Enter the number to count the no. of digits:";
    cin>>num;
    count= countDigits(num);
    cout<<num<<" has "<<count<<" digits";
    return 0;
}