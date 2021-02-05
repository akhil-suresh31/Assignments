/*
    Author : Akhil Suresh
    problem statement: convert a given number to word which follows the indian numbering system

*/

#include<iostream>
#include<string>
#include"Num2Words.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    string number;
    string og,words="";

    cout<<"enter the no to be converted :";
    cin>>number;
    og=number;
    while(num2word(number)=="Invalid input")
    {
        cout<<"Invalid input (too long or is not numeric(negetive no. are allowed)) :";
        cin>>number;
        og=number;
    }
    words= num2word(number);
    cout<<"Given input :"<<og<<"\nConverted to words:"<<words;
    return 0; 
}
