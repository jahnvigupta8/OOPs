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
void preorder(Node* root)
{
	if (root == NULL) return;
	else{
	cout<<root->data<<endl;
	preorder(root->left);
	preorder(root->right);
}
}
void postorder(Node* root)
{
	if (root == NULL) 
	return;
	else{
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<endl;
}
}
void inorder(Node* root)
{
	if (root == NULL) 
	return;
	else{
	inorder(root->left);
	cout<<root->data<<endl;
	inorder(root->right);
}
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
preorder(root);
cout<<endl;
inorder(root);
cout<<endl;
postorder(root);
}
