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
int diff(Node* temp)
{

    int l_height = height(temp->left);
    int r_height = height(temp->right);
    return (l_height - r_height);
}
// Right -Right Rotation
Node* rr_rotation(Node* parent)
{
    Node* temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    cout<<"Right -Right Rotation";
    return temp;
}
//Left- Left Rotation
Node* ll_rotation(Node* parent)
{
    Node* temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    cout<"Left- Left Rotation";
    return temp;
}
// Left - Right Rotation 
Node* lr_rotation(Node* parent)

{
    Node* temp;
    temp = parent->left;
    parent->left = rr_rotation(temp);
    cout<<"Left - Right Rotation ";
    return ll_rotation(parent);
}
     // Right- Left Rotation
Node* rl_rotation(Node* parent)

    {
		Node* temp;
    	temp = parent->right;
    	parent->right = ll_rotation(temp);
    	cout<"Right- Left Rotation";
    	return rr_rotation(parent);
    }
Node* balance(Node* root)
    {
        int bal_factor = diff(root);
        if (bal_factor > 1)
        {
            if (diff(root->left) > 0)
                root = ll_rotation(root);
            else
                root = lr_rotation(root);
            cout<<"hello";    
        }
        else if (bal_factor < -1)
        {
            if (diff(root->right) > 0)
                root = rl_rotation(root);
            else
                root = rr_rotation(root);
            cout<<"no hello";    
        }
        cout<<"done"<<endl;
        return root;
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
root=insert(root,20);
root=insert(root,26);
root=insert(root,21);
root=insert(root,33);
root=insert(root,9);
root=insert(root,8);
root=insert(root,9);
root=insert(root,14);
postorder(root);
cout<<"yo1"<<endl;
balance(root);
cout<<"yo2"<<endl;
postorder(root);
}
