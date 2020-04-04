//Check if a linked list is a palindrome
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
bool helper(node *head, node *tail){
    if(head->data!=tail->data)
        return false;
    node *temp=head;
    node *tail_temp=head;
    while(temp->next!=NULL){
        tail_temp=temp;
        temp=temp->next;
    }   
    tail_temp->next=NULL;
    if(head->next)
      return helper(head->next,tail_temp);
    else
        return true;
    
}
bool check_palindrome(node* head)
{
    node *tail=head;
    while(tail->next!=NULL)
        tail=tail->next;
    helper(head,tail);
     
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
    bool ans=check_palindrome(head);
    if(ans)
        cout<<"true";
    else 
        cout << "false";
    return 0;
}
