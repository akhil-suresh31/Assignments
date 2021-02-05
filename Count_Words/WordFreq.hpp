#include<fstream>
#include<map>
using namespace std;

map<string,int> getWords()
{   
    map<string,int> words;
    ifstream fs;
    string word;
    fs.open("para.txt",ifstream::in);
    while(fs>>word)
    {   
        if(words.count(word))
            words[word]++;
        else
        {
            words[word]=1;
        }
    }
    fs.close();
    return words;
}

int getWordCount(map<string,int> words,string word)
{
    return words.count(word) ? words[word] : 0;
}