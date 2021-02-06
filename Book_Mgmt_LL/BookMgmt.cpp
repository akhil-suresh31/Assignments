/*
    Author : Akhil Suresh
    Q: Book management system using linked list
    features:
        Stores info of books(id, name, author, price) in a linked list;
        does not allow duplicate id books
        insertion of book
        removal of book
        search a perticular book given its id
        view all books
*/
#include<iostream>
#include"BookMgmtLL.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    int ch;
    struct Book b;
    struct list *Head = NULL;
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
                Head = insertBook(Head,b);
                break;
        case 2: int id;
                cout<<"Enter book id to delete:";
                cin>>id;
                Head = removeBook(Head,id);
                break;
        case 3: showAll(Head);
                break;
        case 4: cout<<"Enter book id to search:";
                cin>>id;
                if(!search(Head,id))
                    cout<<"No such book exists";
                break;
        case 5: break;
        default:
                cout<<"invalid option";
                break;
        }
    }while(ch != 5);
    return 0;
}
