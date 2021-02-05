/*  
    author: Akhil Suresh
    q:
        count the occurence of each unique word from a text file
*/
#include<iostream>
#include<map>
#include"WordFreq.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    map<string,int> words = getWords();
    string word;
    cout<<"enter the word to search for:";
    cin>>word;
    int count= getWordCount(words,word);
    if(count==0)
        cout<<"No such word exist in the text file";
    else
        cout<<word<<" occured "<<count<<" times";
   
    return 0;
}
