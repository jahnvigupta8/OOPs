#include<iostream>
using namespace std;
 struct Node
 {
 	int data;
 	Node* left;
 	Node* right;
 };
Node* root; 
Node* getNewNode(int value)
{
	Node* newNode = new Node();
	newNode->data = value;
	newNode->left = NULL;
	newNode->right= NULL;
	return newNode;
}
Node* insert(Node* root , int data)
{
	if (root == NULL)
	{
		root = getNewNode(data);
	}
	else if(data <= root->data)
	{
		root->left = insert(root->left,data);
	}
	else if(data >= root->data)
	{
		root->right = insert(root->right,data);
	}
		return root;		
}
int search(Node* root , int data)
{
	if(root==NULL) return 0;
	else  if(root->data == data) return 1;
	else if(data <= root->data) return search(root->left,data);
	else return search(root->right,data);
 } 
 int min(Node* root )
{
	if (root == NULL)
	{
		cout<<" \n Tree is empty";
	}
	while(root->left != NULL)
	{
		root = root->left;
	}
	return root->data;
	/* else if(root->left==null)
	{
		return root->data;      // recursion
	}
	return min(root->left)*/
}
int max(Node* root )
{
	if (root == NULL)
	{
		cout<<" \n Tree is empty";
	}
	while(root->right != NULL)
	{
		root = root->right;
	}
	return root->data;
	/* else if(root->right==null)
	{
		return root->data;      // recursion
	}
	return min(root->right)*/
}
int height(Node* root)
{
	if (root == NULL)
	{
		return -1;
	}
	return max(height(root->left),height(root->right))+1;
}
int main()
{
root = NULL;
root=insert(root,15);
root=insert(root,10);
root=insert(root,23);
root=insert(root,25);
root=insert(root,13);
root=insert(root,11);
root=insert(root,6);
int n;
cout<<"Enter the number you want to search : \t ";
cin>>n;
//cout<<root->left<<endl;
if(search(root ,n)== 1)
cout<<"\n FOUND";
else
cout<<"\n NOT FOUND";
cout<<"\nMAXIMUM NUMBER IN TREE : \t"<<max(root);
cout<<"\nMINIMUM NUMBER IN TREE : \t"<<min(root);
cout<<"\n HEIGHT OF TREE :\t "<<height(root);
}
 
