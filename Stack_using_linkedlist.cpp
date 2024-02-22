#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define fr(i,a,b) for (int i = a; i < b; i++)
struct node{
    int data;
    struct node *next;
};
struct node* top=NULL;
void push(int val){
    struct node* newnode=(struct node*) malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=top;
    top=newnode;
}
void pop(){
    if(top==NULL){
        cout<<"Stack Underflow"<<endl;
    }else{
        cout<<"The popped element"<<top->data<<endl;
        top=top->next;
    }
}
void display(){
    struct node* ptr;
    if(top==NULL){
       cout<<"stack is empty";
    }
    else{
        ptr=top;
        cout<<"stack element are:";
        while(ptr!=NULL){
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
    }
    cout<<endl;
}

int main(){
   
   int ch,val;
   push(4);
   push(5);
   push(6);
   push(7);
   pop();
   return 0;
}