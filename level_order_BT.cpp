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
void levelOrder(Node* root)
{
	if (root == NULL) return;
	queue<Node*> Q;
	Q.push(root);
	while(! Q.empty())
	{
		Node* current = Q.front();
		cout<<current->data<<" ";
		if(current->left != NULL) Q.push(current->left);
		if(current->right != NULL) Q.push(current->right);
		Q.pop();
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
levelOrder(root);
}
