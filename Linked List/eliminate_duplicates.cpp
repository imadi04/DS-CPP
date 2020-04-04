//Eliminate duplicates from a sorted linked list
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
node* eliminate_duplicate(node* head)
{
    //write your code here
    
    if(!head->next)
        return head;
    node *temp;
    node *start=head;
    node *final_head;
    temp=eliminate_duplicate(head->next);
    if(temp->data==start->data){
        final_head=temp;
    }
    else{
        start->next=temp;
        final_head=start;
    }
    return final_head;
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
    head=eliminate_duplicate(head);
    print(head);
    return 0;
}

