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
cout<<"\n HEIGHT OF TREE :\t "<<height(root);

}
