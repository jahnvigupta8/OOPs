#include<iostream>
#include<cstring>
void push(int);
void pop();
using namespace std;
static int a[20];
static int top=0;
void push(int x){
	a[top]=x;
	top++;
	
}
void pop(){
	top--;
}
int main(){
	string st;
	cin>>st;
	int l;
	int i=0;
	l=st.length();
	while(l!=0){
		if(st[i]=='('||st[i]=='{'||st[i]=='['){
			push(st[i]);
			i++;
		}
		else if(st[i]==')'||st[i]=='}'||st[i]==']'){
			if(top==0){
				cout<<"Not a correct string!!"<<endl;
				return 0;
			}
			else if(a[top-1]=='('){
					if(st[i]==')'){
						pop();
					}
					else{
										cout<<"Not a correct string!!"<<endl;

						return 0;
					}				
			}	
			else if(a[top-1]=='{'){
					if(st[i]=='}'){
						pop();
					}
					else{
										cout<<"Not a correct string!!"<<endl;
						return 0;
					}				
			}
			else if(a[top-1]=='['){
					if(st[i]==']'){
						pop();
					}
					else{
									cout<<"Not a correct string!!"<<endl;

						return 0;
					}				
			}
			i++;
			}
			else{
				i++;
				continue;
			}	
		l--;
	}
			cout<<"This is a correct expression!!"<<endl;
}
