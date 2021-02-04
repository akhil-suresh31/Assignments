/*
    Author: Akhil Suresh
    q: Book management system using map
    features:
        Stores info of books(id, name, author, price) in a map (uses id as the key);
        insertion of new book , with id check(no books with same id)
        removal of book
        search a book
        show all books
*/

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

void insertBook(map<int,struct Book> &Books ,struct Book b)
{
   if(Books.count(b.b_id)>0)
   {
       cout<<"Book already exists with same id";
       return;
   }
   Books[b.b_id]=b;
}

void removeBook(map<int,struct Book> &Books ,int id)
{
   if(Books.count(id)==0)
   {
       cout<<"no such book exists";
       return;
   }
    cout<<"removed book :"<<Books[id].b_name;
    Books.erase(id);
}

void search(map<int,struct Book> &Books,int id)
{
    if(Books.count(id))
    {
        cout<<"----------------------------------\n";
        cout<<"Book id:"<<Books[id].b_id;
        cout<<"\nBook name :"<<Books[id].b_name;
        cout<<"\nBook author:"<<Books[id].b_author;
        cout<<"\nBook price :"<<Books[id].b_price;
        cout<<"\n-----------------------------------\n";
    }
    else
    {
        cout<<"No such book exists";
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

int main(int argc, char const *argv[])
{
    int ch;
    struct Book b;
    map<int,struct Book> Books;
    do
    {
        cout<<"\nBook management menu : \n1.Add book\n2.Remove book\n3.View books\n4.Search\n5.Exit";
        cout<<"\nEnter your choice:";
        cin>>ch;
        switch(ch)
        {
        case 1:
                cout<<"Enter book id:";
                cin>>b.b_id;
                cout<<"Enter book name :";
                cin>>b.b_name;
                cout<<"Enter author:";
                cin>>b.b_author;
                cout<<"Enter price:";
                cin>>b.b_price;
                insertBook(Books,b);
                break;
        case 2: int id;
                cout<<"Enter book id to delete:";
                cin>>id;
                removeBook(Books,id);
                break;
        case 3: showAll(Books);
                break;
        case 4: cout<<"Enter book id to search:";
                cin>>id;
                search(Books,id);
                break;
        case 5:break;
        default:
                cout<<"invalid option";
                break;
        }
    }while(ch != 5);
    return 0;
}
