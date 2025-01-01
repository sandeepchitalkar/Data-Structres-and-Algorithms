//Binary Tree Implementaiton and BFS Traversal
#include<iostream>
#include<queue>
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
	void BFStraverse();
	void insert(node*,node*);
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
			case 2:b.BFStraverse(); // DFS traversal of Binary Tree
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

// Function to perform BFS (level order traversal)
void BT::BFStraverse() {
    if (root == nullptr) {
        return;
    }

    // Create a queue to hold nodes for level-order traversal
    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        // Get the front node from the queue
        node* current = q.front();
        q.pop();

        // Print the current node's data
        cout << current->data << " ";

        // Push left child to the queue if it exists
        if (current->left != nullptr) {
            q.push(current->left);
        }

        // Push right child to the queue if it exists
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}
