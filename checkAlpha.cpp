/*
    Author: Akhil Suresh
    q: Program to check if entered character is alphabet or not
*/
#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    char c;
    cout<<"Enter a character:";
    cin>>c;
    if(('a'<=c && c<='z') || ('A'<=c&&c<='Z'))
        cout<<"Entered character is an alphabet";
    else
        cout<<"entered character is not an alphabet";
    
    return 0;
}
