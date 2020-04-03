#include <iostream>
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

using namespace std;
//iterative
Node* deleteNode(Node *head, int i) { 
    Node *temp=head;
    if(i==0){
        head=temp->next;
        delete [] temp;
        return head;
    }
    
    Node *a;
    int count=0;
    while(temp!=NULL && count<i-1){
        temp=temp->next;
        count++;
    }
    if(temp!=NULL){
        a=temp->next;
        if(a!=NULL)
            temp->next=a->next;
        delete [] a;
    }
    return head;
}
//Recursive
Node* deleteNodeRec(Node *head, int i) {
    if(!head)
        return head;
    if(i==0){
        head=head->next;
        return head;
    }
    Node *x;
    Node *temp=head;
    x=deleteNodeRec(head->next,i-1);
    temp->next=x;
    head=temp;
    return head;
}

Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main() {
    Node *head = takeinput();
    int pos;
    cin >> pos;
    head = deleteNode(head, pos);
    print(head);
    return 0;
}

