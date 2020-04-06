//Arrange elements in a Linked List such that all even numbers are placed after odd numbers
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
node* arrange_LinkedList(node* head)
{
    //write your code here
    if(!head->next)
        return head;
    node *oh=0,*ot=0,*eh=0,*et=0;
    while(head){
        if(head->data%2==0){
            if(eh==0){
                eh=head;
                et=head;
            }
            else{
                et->next=head;
                et=head;
            }
           
            head=head->next;
        }
        else{
            if(oh==0){
                oh=head;
                ot=head;
            }
            else{
                ot->next=head;
                ot=head;
            }
            head=head->next;
        }
    }
    
	if(et)
    	et->next=0;
    if(ot)
    	ot->next=0;
    if(ot!=0 && eh!=0)
    	ot->next=eh;
    if(oh==0 && eh!=0)
    	return eh;
    else
        return oh;
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
int main()
{
    node*head=takeinput();
    head=arrange_LinkedList(head);
    print(head);
    return 0;
}
