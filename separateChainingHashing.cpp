//Separate chaining implementation in hashing
//Showing only insert operation using linked list

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

int main()
{
    //init array of list to NULL
    init();

   //Data inserted in hash table 
    insert(7);
    insert(0);
    insert(13);
    insert(10);
    insert(4);
    insert(15);

    print();

    return 0;
}
