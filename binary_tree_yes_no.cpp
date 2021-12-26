#include<iostream>
#include<queue>
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
int IsLeftSubTreeLesser(Node* root,int value)
{
	if (root == NULL) return 1;
	if(root->data<=value && IsLeftSubTreeLesser(root->left,value) && IsLeftSubTreeLesser(root->right,value))
	return 1;
	else 
	return 0;
}
int IsRightSubTreeGreater(Node* root,int value)
{
	if (root == NULL) return 1;
	if(root->data>value && IsRightSubTreeGreater(root->left,value) && IsRightSubTreeGreater(root->right,value))
	return 1;
	else 
	return 0;	
}
int IsBinarySearchTree(Node* root)
{
	if(IsLeftSubTreeLesser(root->left,root->data)&&IsRightSubTreeGreater(root,root->data)&&IsBinarySearchTree(root->left)&&IsBinarySearchTree(root->right))	
	return 1;
	else return 0;
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
cout<<"check if it is a binary tree : \t ";
if(IsBinarySearchTree(root)== 1)
cout<<"\n YES";
else
cout<<"\n NO ";
}
