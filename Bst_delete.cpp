 #include<iostream>
 #include<algorithm>
using namespace std;
 struct Node
 {
 	int data;
 	Node* left;
 	Node* right;
 };
Node* root; 
Node* min(Node* root )
{
	if (root == NULL)
	{
		cout<<" \n Tree is empty";
	}
	while(root->left != NULL)
	{
		root = root->left;
	}
	return root ;
	/* else if(root->left==null)
	{
		return root->data;      // recursion
	}
	return min(root->left)*/
}
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
Node* deleteNode(Node* root,int data)
{
	if(root==NULL) return root;
	else if(data<root->data) root->left=deleteNode(root->left,data);
	else if(data >root->data) root->right=deleteNode(root->right,data);
	else
	{
		//case 1 : zero child
		if(root->left == NULL && root->right==NULL)
		{
			delete root;
			root = NULL;
			cout<<"null"<<endl;
			return root;
	
		}
		//case 2 one child
		else if(root->left==NULL)
		{
			Node* temp = root;
			root= root->right;
		
			delete temp;
			cout<<"left 1"<<endl;
			return root;

		}
		else if(root->right==NULL)
		{
			Node* temp = root;
			root= root->left;
			delete temp;
			cout<<"right 1"<<endl;
			return root;
			
		}
		//case :2 child
		else
		{
			Node* temp = min(root->right);
			root->data=temp->data;
			root->right = deleteNode(root->right,temp->data);
			cout<<"2"<<endl;
			return root;
		}
	}
	return root;
	cout<<"done"<<endl;
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
root=insert(root,24);
root=insert(root,33);
inorder(root);
deleteNode(root,25);
inorder(root);
}

