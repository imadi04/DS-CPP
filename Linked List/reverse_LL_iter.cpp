// Reverse Linked List  a. Using recursion  b. Without using recursion
#include <iostream>
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
using namespace std;
node* rev_linkedlist_itr(node* head)
{
    
    node *curr=head;
    node *prev=0;
    node *n;
    while(curr){
        n=curr->next;
        curr->next=prev;
        prev=curr;
        curr=n;
    }
    return prev;
}

node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    node* head=takeinput();
    head=rev_linkedlist_itr(head);
    print(head);
    return 0;
}



