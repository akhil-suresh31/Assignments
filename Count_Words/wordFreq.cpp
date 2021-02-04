/*  
    author: Akhil Suresh
    q:
        count the occurence of each unique word from a text file
*/
#include<iostream>
#include<map>
#include<fstream>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
    map<string,int> words;

    ifstream fs;
    string word;
    fs.open("para.txt",ifstream::in);
    while(fs>>word)
    {   
        
        if(words.count(word)==1)
            words[word]++;
        else
        {
            words[word]=1;
        }
    }

    fs.close();

    cout<<"words : count\n";
    for( pair<string,int> i : words)
    {   
        cout<<i.first<<":"<<i.second<<endl;
    }

    return 0;
}
