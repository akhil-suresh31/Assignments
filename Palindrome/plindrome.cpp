/*
    Author: Akhil Suresh
    Q: giiven a string check if its palindrome or not (i.e its the same if its backwards)
*/

#include<iostream>
#include"palindrome.hpp"

using namespace  std;
 
int main(int argc, char const *argv[])
{
    string str;
    cout<<"Enter string to check for palindrome(case sensitive):";
    cin>>str;
    if(palindrome(str))
        cout<<"Palindrome";
    else
    {
        cout<<"not palindrome";
    }
    return 0;
}
