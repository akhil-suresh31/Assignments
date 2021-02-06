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
#include"BookMgmtMap.hpp"
using namespace std;

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
                if(insertBook(Books,b))
                    cout<<"Book inserted successfully";                  
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
                if(search(Books,id))
                {
                    cout<<"----------------------------------\n";
                    cout<<"Book id:"<<Books[id].b_id;
                    cout<<"\nBook name :"<<Books[id].b_name;
                    cout<<"\nBook author:"<<Books[id].b_author;
                    cout<<"\nBook price :"<<Books[id].b_price;
                    cout<<"\n-----------------------------------\n";
                }
                break;
        case 5:break;
        default:
                cout<<"invalid option";
                break;
        }
    }while(ch != 5);
    return 0;
}
