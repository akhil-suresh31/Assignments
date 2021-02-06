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
};

int book_count(struct list *Head){

    if(Head == NULL)
        return 0;
    int count=0;
    struct list *temp = Head;
    while(temp!=NULL)
    {    count++;
         temp= temp->next;
    }
    return count;
}

bool search(struct list *Head,int id)
{
    struct list *temp = Head;
    while(temp)
    {   
        if(temp->info.b_id == id)
        {
            cout<<"\n----------------------------------\n";
            cout<<"Book id :"<<temp->info.b_id;
            cout<<"\nBook name:"<<temp->info.b_name;
            cout<<"\nBook author:"<<temp->info.b_author;
            cout<<"\nBook price :"<<temp->info.b_price;
            cout<<"\n-----------------------------------\n";
            return true;
        }
        temp = temp->next;
    }
    return false;
}


struct list* insertBook(struct list *Head,struct Book b)
{
    struct list *member =new struct list;
    member->info = b;
    member->next = NULL;
    if(Head)
    {   
        if(search(Head,b.b_id))
        {
            cout<<"\nBook already exists with the same id:"<<b.b_id;
            return Head;
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
    return Head;
}

struct list * removeBook(struct list *Head,int id)
{
    if(Head == NULL)
    {
        cout<<"\nno book to remove";
        return Head;
    }
    struct list *temp = Head,*prev;
    if(temp->info.b_id == id){
        cout<<"\nremoved book :"<<temp->info.b_name;
        Head = Head->next;
        return Head;
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
        cout<<"\nno such book exist";
        return Head;
    }
    prev->next = temp->next;
    cout<<"\nremoved book :"<<temp->info.b_name;
    return Head;
}

void showAll(struct list *Head)
{
    if(Head == NULL)
    {
        cout<<"\nBook inventory empty";
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