/*
    Author: Akhil Suresh
    q: given a string count the occurence of each digit
*/
#include<iostream>
#include"OccurDigits.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    string num;
    int *arr;
    arr= (int *)calloc(10,sizeof(int));
    cout<<"Enter the string to count the digits:";
    cin>>num;
    arr=countDig(num,arr);
    cout<<" Digit : Occurance\n";
    for(int i=0;i<10;i++)
    {
        cout<<i<<" : "<<arr[i]<<endl;
    }
    return 0;
}
