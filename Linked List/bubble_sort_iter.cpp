//bubble sort iterative
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
node* bubble_sort_LinkedList_itr(node* head)
{
    //write your code here
    node *temp=head;
    int c=0;
    while(temp){
        c++;
        temp=temp->next;
    }
    //cout<<c;
    for(int i=0;i<c;i++){
        node *curr=head;
    node *prev=0;
        while(curr->next){
        if(curr->data > curr->next->data){
            if(prev==NULL){
                node *t;
                t=curr->next;
                curr->next=t->next;
                t->next=curr;
                prev=t;
                head=prev;
                //cout<<prev->data<<endl;
            }
            else{
               
              node *n;
            prev->next=curr->next;
            n=curr->next;
            curr->next=n->next;
            n->next=curr;
            prev=prev->next;  
            }
            
        }
        else{
            prev=curr;
            curr=curr->next;
        }
    }
    }
    
    return head;
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
    node* head=takeinput();
    head=bubble_sort_LinkedList_itr(head);
    print(head);
}

