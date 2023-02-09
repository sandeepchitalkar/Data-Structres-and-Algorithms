//Separate chaining implementation in hashing
//Showing only insert and Delete operation using linked list

#include <iostream>
using namespace std;
#define size 7

struct node
{
    int data;
    struct node *next;
};

struct node *chain[size];

void init()
{
    int i;
    for(i = 0; i < size; i++)
        chain[i] = NULL;
}

void insert(int value)
{
    //create a newnode with value
    struct node *newNode = new node;
    newNode->data = value;
    newNode->next = NULL;

    //calculate hash key
    int key = value % size;

    //check if chain[key] is empty
    if(chain[key] == NULL)
        chain[key] = newNode;
    //collision
    else
    {
        //add the node at the end of chain[key].
        struct node *temp = chain[key];
        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void print()
{
    int i;

    for(i = 0; i < size; i++)
    {
        struct node *temp = chain[i];
        cout<<"Chain"<<i<<"-->";
        while(temp)
        {
            cout<<temp->data<<"-->";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
}

/*
 * return 1 is used when element successful delete from hash table
 * return 0, value not found
 */
int del(int value)
{
    int key = value % size;
    struct node *temp = chain[key], *dealloc;
    if(temp != NULL)
    {
        if(temp->data == value)
        {
            dealloc = temp;
            temp = temp->next;
            delete dealloc;
            return 1;
        }
        else
        {
            while(temp->next)
            {
                if(temp->next->data == value)
                {
                    dealloc = temp->next;
                    temp->next = temp->next->next;
                    delete dealloc;
                    return 1;
                }
                temp = temp->next;
            }
        }
    }

    return 0;
}


int main()
{
    //init array of list to NULL
    init();

   //Data inserted in hash table 
    insert(7);
    insert(20);
    insert(3);
    insert(10);
    insert(4);
    insert(5);

  
    print();

    cout<<"\n Perform Deletion operation for element 10\n";

    if(del(10))
    {
        cout<<"After Deletion of 10\n";
        print();
     }
    else
        cout<<"Value Not Present\n";


    return 0;
}
