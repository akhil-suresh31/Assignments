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
using namespace std;

struct Book
{
    int b_id;
    string b_name;
    string b_author;
    float b_price;
};

struct list
{
    struct Book info;
    struct list *next;
} *Head = NULL;


void insertBook(struct Book b)
{
    struct list *member =(struct list *)malloc(sizeof(struct list));
    member->info = b;
    member->next = NULL;

    if(Head)
    {   
        if(search(b.b_id))
        {
            cout<<"Book already exists with the same id";
            return;
        }
        struct list *temp=Head;
        while(temp->next)
        {   
            temp = temp->next;
        }
        temp->next = member;
    }
    else
    {
        Head = member;
       
    }
}

bool search(int id)
{
    if(Head == NULL)
    {
        cout<<"List is empty";
        return false;
    }
    struct list *temp = Head;
    while(temp)
    {   
        if(temp->info.b_id == id)
        {
             cout<<"----------------------------------\n";
            cout<<"Book id :"<<temp->info.b_id;
            cout<<"\nBook name:"<<temp->info.b_name;
            cout<<"\nBook author:"<<temp->info.b_author;
            cout<<"\nBook price :"<<temp->info.b_price;
            cout<<"\n-----------------------------------\n";
            return true;
        }
        temp = temp->next;
    }
    cout<<"no such book exist";
    return false;
}

void removeBook(int id)
{
    if(Head == NULL)
    {
        cout<<"no book to remove";
        return;
    }
    struct list *temp = Head,*prev;
    if(temp->info.b_id == id){
        cout<<"removed book :"<<temp->info.b_name;
        Head = Head->next;
        return;
    }
    while(temp)
    {   
        if(temp->info.b_id == id)
        {
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL)
    {
        cout<<"no such book exist";
        return;
    }
    prev->next = temp->next;
    cout<<"removed book :"<<temp->info.b_name;
}

void showAll()
{
    if(Head == NULL)
    {
        cout<<"Book inventory empty";
        return;
    }
    struct list *temp=Head;
    while(temp)
    {   cout<<"----------------------------------\n";
        cout<<"Book id :"<<temp->info.b_id;
        cout<<"\nBook name:"<<temp->info.b_name;
        cout<<"\nBook author:"<<temp->info.b_author;
        cout<<"\nBook price :"<<temp->info.b_price;
        cout<<"\n-----------------------------------\n";
        temp = temp->next;
    }
}

int main(int argc, char const *argv[])
{
    int ch;
    struct Book b;
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
                insertBook(b);
                break;
        case 2: int id;
                cout<<"Enter book id to delete:";
                cin>>id;
                removeBook(id);
                break;
        case 3: showAll();
                break;
        case 4: cout<<"Enter book id to search:";
                cin>>id;
                search(id);
                break;
        case 5: break;
        default:
                cout<<"invalid option";
                break;
        }
    }while(ch != 5);
    return 0;
}
