/*
    Author: Akhil Suresh
    q: given a string count the occurence of each digit
*/
#include<iostream>
#include<string>
using namespace std;

void countDig(string no)
{  
    int arr[]={0,0,0,0,0,0,0,0,0,0};
    for(int i=0;i<no.length();i++)
    {  int dig=no[i]-'0';
        arr[dig]++;

    }
    cout<<"Digits and their occurence:\n";
    for(int i=0 ;i <10; i++)
    {
        cout<<i<<":"<<arr[i]<<endl;
    }
}

int main(int argc, char const *argv[])
{
    string num;
    cout<<"Enter the string to count the digits:";
    cin>>num;
    countDig(num);
    return 0;
}
