//Create a Binary Tree using Linked representation and traversal Binary Tree using DFS Traversal Recursive and Non Recursive 
#include<iostream>
#include<conio.h>
using namespace std;
// Binary Tree Node Structure
class node 
{
	public:
	    node *left;
	    node *right;
	    int data;
};

//Class to implement ADT of Binary Tree
class BT
{
	public:
	node *root;
	node *st[10];
	int top;
	BT()
	{
		root=NULL;
		top=-1;
	}
	void create();
	void traverse();
	void insert(node*,node*);
	void preorder(node*);
	void postorder(node*);
	void inorder(node*);
	void push(node*);
	node* pop();
	void npreorder(node*);
	void ninorder(node*);
	int npostorder(node*);
};
int main()
{
	BT b; //object of class BT
	int ch;
	do
	{
		cout<<"\n1.create\n2.traverse\n";
		cout<<"Enter Your Choice:\n";
		cin>>ch;
		switch(ch)
		{
			case 1:b.create();  //Create a Binary Tree
			       break;
			case 2:b.traverse(); // DFS traversal of Binary Tree
			       break;
			default: cout<<"Wrong choice";
				break;
		}
	}while(ch!=3);
    return 0;
}

//function to create Binary Tree
void BT::create() 
{
	node *temp;
	int value;
	char ch;
	do
	{
		cout<<"Enter the value:\n";
		cin>>value;
		temp=new node;   //Create a new node
		temp->data=value;  //Read the data and store in temp node
		temp->left=NULL;  //make left child link NULL
		temp->right=NULL; //make Right child link NULL
		if(root==NULL)
		{
			root=temp;   //make first node as root node
		} 
		else
		{
			insert(root,temp); //insert new node in Binary Tree
		}
		cout<<"Want to insert an node in Binary Tree Press Y or N:\n";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
}

//Insert function used to insert new node as per left or right choice recursively
void BT::insert(node *root,node *temp)
{
	char ch;
	cout<<"\n Where to insert "<< temp->data<<" Left of- "<< root->data<<" or Roght of- "<<root->data<<" Enter L or R";
	cin>>ch;
	if(ch=='l'||ch=='L')  
	{
		if(root->left==NULL) //if left child not present then add new node as left child
		{
		    root->left=temp;
		}
		else
		{
			insert(root->left,temp); //recursively call insert function
		}
	}
	else
	{
		if(root->right==NULL) //if right child not present then add new node as right child
		{
			root->right=temp;
		}
		else
		{
			insert(root->right,temp); //recursively call insert function
		}
	}
}
void BT::push(node *temp)
{
	top++;
	st[top]=temp;
}
node* BT::pop()
{
	return st[top--];
}
void BT::traverse()
{
	int ch;
	cout<<"\n1.Preorder\n2.inorder\n3.postorder\n4.Non_recpreorder\n5.Non_recinorder\n6.Non_recpostorder\n";
	cout<<"Enter Your Choice:\n";
	cin>>ch;
	switch(ch)
	{
		case 1:preorder(root); //call recurive DFS method
			break;
		case 2:inorder(root);//call recurive DFS method
			break;
		case 3:postorder(root);//call recurive DFS method
			break;
		case 4:npreorder(root);//call non recurive DFS method
			break;
		case 5:ninorder(root);//call non recurive DFS method
			break;
		case 6:npostorder(root);//call non recurive DFS method
			break;
		default:cout<<"Wrong choice";
			break;
	}
}
void BT::preorder(node *temp) //Recursive preorder traversal
{
	if(temp!=NULL)
	{
	cout<<"\t"<<temp->data; // Visit the root node
	preorder(temp->left); // Traverse the left subtree
	preorder(temp->right);// Traverse the right subtree
	}
}
void BT::inorder(node *temp)
{
	if(temp!=NULL)
	{
	inorder(temp->left);// Traverse the left subtree
	cout<<"\t"<<temp->data;// Visit the root node
	inorder(temp->right);// Traverse the right subtree
	}
}
void BT::postorder(node *temp)
{
	if(temp!=NULL)
	{
	postorder(temp->left);// Traverse the left subtree
	postorder(temp->right);// Traverse the right subtree
	cout<<"\t"<<temp->data;// Visit the root node
	}
}
void BT::npreorder(node *root)
{
	node *temp;
	temp=root;
	while(1)
	{
		if(temp!=NULL)
		{
			cout<<"\t"<<temp->data;
			if(temp->right!=NULL)
			     push(temp->right); //push the node 
			     temp=temp->left;
		}
		else
		{
			if(top!=-1)
			{
				temp=pop();
			}
			else
			{
				break;
			}
		}
	}
}
void BT::ninorder(node *root)
{
	node *temp;
	temp=root;
	while(1)
	{
		if(temp!=NULL)
		{
			push(temp);
			temp=temp->left;
		}
		else
		{
			if(top!=-1)
			{
				temp=pop();
				cout<<"\t"<<temp->data;
				temp=temp->right;
			}
			else
			{
				break;
			}
		}
	}

}
int BT::npostorder(node *root)
{
	node *temp;
	temp=root;
	while(1)
	{
		if(temp!=NULL)
		{
			push(temp);
			if(temp->right!=NULL)
			push(temp->right);
			temp=temp->left;
		}
		else
		{
			while(1)
			{
			if(top!=-1)
			    {
				temp=pop();
				cout<<"\n"<<temp->data;
			    }
			else
			    {
				break;
			    }
			}
			return 0;
		}
	}
}
