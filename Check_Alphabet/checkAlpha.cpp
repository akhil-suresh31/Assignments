/*
    Author: Akhil Suresh
    q: Program to check if entered character is alphabet or not
*/
#include<iostream>
#include"CheckAlpha.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    char c;
    cout<<"Enter a character:";
    cin>>c;
    if(checkAlpha(c))
        cout<<"Entered character is an alphabet";
    else
        cout<<"entered character is not an alphabet";
    return 0;
}
