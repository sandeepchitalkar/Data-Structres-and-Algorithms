/* To create a binary tree using an array in C++ and accept each node's data from the user, we can follow the concept of complete binary tree representation using an array. In this representation, the array indices correspond to the tree nodes in the following way:
The root of the tree is at index 0.
For any node at index i:
The left child is at index 2i + 1.
The right child is at index 2i + 2.
The parent is at index (i - 1) / 2.
*/
#include <iostream>
#include <vector>
using namespace std;

// Function to accept input and create the binary tree using an array
void createBinaryTree(vector<int>& treeArray, int n) {
    cout<<"Enter the data for the binary tree nodes press -1 if no Left or right child want to add:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Node " << i + 1 << ": ";
        cin >> treeArray[i];
    }
}

// Function to print the binary tree in level order (array representation)
void printBinaryTree(const vector<int>& treeArray, int n) {
    cout << "Binary Tree in level order:\n";
    cout <<"| ";
    for (int i = 0; i < n; ++i) {
        cout << treeArray[i] << " |";
    }
    cout << endl;
}

void getLeftRightChildIndex(const vector<int>& treeArray, int pindex)
{
    int lIndex=0, rIndex=0;
    lIndex=((2*pindex)+1);//calculate Left child index
    rIndex=((2*pindex)+2);//calculate Right child index
    cout<<"Left child of the "<<treeArray[pindex]<<"is:"<<treeArray[lIndex]<<endl;
    cout<<"Right child of the "<<treeArray[pindex]<<"is:"<<treeArray[rIndex]<<endl;
}

void getParentIndex(const vector<int>& treeArray, int cIndex)
{
    int pIndex=0;
    pIndex=((cIndex-1)/2); //calculate parent node index
    cout << "The parent of the node at index " << cIndex <<" is :"<<treeArray[pIndex];
}

int main() {
    int n,size,pindex,cIndex;

    // Ask for the number of nodes in the binary tree
    cout << "Enter the number of nodes in the binary tree: ";
    cin >> n;
    size=((2*n)+1); //Total size of array to show no child data of each leaf node
    // Create an array to store the binary tree
    vector<int> treeArray(size,-1); //Initalize it with -1 to show NULL

    // Accept input from the user to populate the binary tree
    createBinaryTree(treeArray, n);

    // Print the binary tree (array representation)
    printBinaryTree(treeArray, size);
    
    //Print the left and right child of the parent node
    cout << "Enter the Index of parent node (less than"<<n<<": ";
    cin>>pindex;
    if(pindex>=0 && pindex<=n)
        getLeftRightChildIndex(treeArray,pindex);
    else
        cout<<"\n Enter the valid parent index";
    
    //Print the parent node index for Left and right child
    cout << "Enter the Index of child node (less than)"<<n<<": ";
    cin>>cIndex;
    if(cIndex>=1 && cIndex<=n)
        getParentIndex(treeArray,cIndex);
    else
        cout<<"\n Enter the valid child index";

    return 0;
}
