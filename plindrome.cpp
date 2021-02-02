/*
    Author: Akhil Suresh
    Q: giiven a string check if its palindrome or not (i.e its the same if its backwards)
*/

#include<iostream>
#include<string>

using namespace  std;

bool palindrome(string str){
  for(int i = 0; i < str.length()/2; i++)
    {
        if(str[i] != str[str.length()-i-1])
            return false;
    }
    return true;
}

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
