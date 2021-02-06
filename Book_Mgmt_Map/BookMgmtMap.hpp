#include<iostream>
#include<map>
using namespace std;

struct Book
{
    int b_id;
    string b_name;
    string b_author;
    float b_price;
};

bool insertBook(map<int,struct Book> &Books ,struct Book b)
{
   if(Books.count(b.b_id)>0)
   {
       cout<<"\nBook already exists with same id";
       return false;
   }
   Books[b.b_id]=b;
   return true;
}

bool removeBook(map<int,struct Book> &Books ,int id)
{
    if(Books.size() == 0)
    {
        cout<<"\nNo books to remove List is empty";
        return false;
    }
    if(Books.count(id)==0)
    {
        cout<<"\nNo such book exists";
        return false;
    }
    cout<<"\nRemoved book :"<<Books[id].b_name;
    Books.erase(id);
    return true;
}

bool search(map<int,struct Book> &Books,int id)
{   
    if(Books.size() == 0)
    {
        cout<<"\nMap is empty";
        return false;
    }
    if(Books.count(id))
    {
        return true;
    }
    else
    {
        cout<<"\nNo such book exists";
        return false;
    }
    
}

void showAll(map<int,struct Book> &Books)
{
    if(Books.empty())
    {
        cout<<"No Books to show";
        return;
    }
    for(pair<int,struct Book> i : Books)
    {
        cout<<"----------------------------------\n";
        cout<<"Book id:"<<i.second.b_id;
        cout<<"\nBook name :"<<i.second.b_name;
        cout<<"\nBook author:"<<i.second.b_author;
        cout<<"\nBook price :"<<i.second.b_price;
        cout<<"\n-----------------------------------\n";
    }
}