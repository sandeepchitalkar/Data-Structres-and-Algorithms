/*   Inorder Binary Threaded Tree -With Traversal */
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
class node
{
 public:
	int data;
	int lth;
	int rth;
	node *lptr;
	node *rptr;
};



class TBT
{
  public:
       node* root;
       node* dummy;

       TBT()
	{
	  root=NULL;
	  dummy=NULL;
	 }

       void create();
       void insert(node *,node *);
       void menu_display(void);
       void tbt_display(node *);

};


//MAIN FUNCTION
 int main()
  {
       TBT b;
       //clrscr();

       cout<<"\n";
       b.menu_display();

       cout<<"\n";
    return 0;

  }

//FUNCTION DEFINITIONS

void TBT::create()
{
   int value;
   char op;
   node *temp;

	do
	{
		cout<<"\n  Enter The Integer Value  ";
		cin>>value;

		temp=new node;

		temp->data=value;
		temp->lptr=NULL;
		temp->rptr=NULL;
		temp->lth=temp->rth=0;
		if(root==NULL)
		{

		  dummy= new node;
		  //dummy node created
		  dummy->data=999;
		  dummy->lptr=root;
		  dummy->rptr=dummy;
		  dummy->lth=1;
		  dummy->rth=0;

		  root=temp;
		  //root points to dummy
		  root->lptr=dummy;
		  root->rptr=dummy;
		}
		else
		{
		  insert(root,temp);
		}

	       cout<<"\n Do You Want To Insert More ?(y/n)   ";
            cin>>op;
	}while(op=='y');
}

void TBT::insert(node *root,node *temp)
{

	if(temp->data< root->data)        //look for left subtree
	 {
			if(root->lth==0)
			 {
			  temp->lptr=root->lptr;
			  temp->rptr=root;
			  root->lptr=temp;
			  root->lth=1;
			 }
			else
			  insert(root->lptr,temp);
	 }
	else
	 {
	  if(temp->data> root->data)   //look for right subtree
	   {
			 if(root->rth==0)
			   {
			     temp->rptr=root->rptr;
			     temp->lptr=root;
			     root->rptr=temp;
			     root->rth=1;
			   }
			 else
			   insert(root->rptr,temp);
	   }
	  else
	   {
	    cout<<"\nNode Already Exists, Re-enter...  ";
	    create();
	   }
	 }

}


 void TBT::menu_display()
  {
    int ch;
    char op1;
    node *temp;

    do
    {
    cout<<"\nDisplay Menu ";
    cout<<"\n1. Create TBT";
    cout<<"\n2. Display TBT";

    cout<<"\nEnter Choice ";
    cin>>ch;

    switch(ch)
     {
       case 1:
	      create();
	      break;
       case 2:
	      tbt_display(root);
	      break;

       default:
	      cout<<"\nInvalid Choice ";
	      menu_display();
     }

    cout<<"\nGo Back To Display Menu ?(y/n) ";
    cin>>op1;
    }while(op1=='y');
  }


//Functions

void TBT::tbt_display(node *temp)
  {

	if(temp!=NULL)
	{
	   while(temp->lth!=0)
		temp=temp->lptr;

	   while(temp!=root)
		{
		cout<<" "<<temp->data;
		temp=temp->rptr;
		}

	   cout<<" "<<temp->data;
	   temp=temp->rptr;

	   while(temp->lth!=0)
		temp=temp->lptr;


	   while(temp!=dummy)
		{
		cout<<" "<<temp->data;
		temp=temp->rptr;
		}
	   }
	   else
		cout<<"TBT doent Exist";
  }
