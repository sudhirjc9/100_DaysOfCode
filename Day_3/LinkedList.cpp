#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

node* insert(node* head, int val)
{
    node* temp = new node(val);
    if(head==NULL)
        return temp;

    node* curr = head;
    while(curr->next != NULL)
        curr = curr->next;

    curr->next = temp;
    return head;
}

void printLinkedList(node *head)
{
    if(head == NULL)
        return;

    node* curr = head;
    while(curr != NULL)
        {

            cout<<curr->data<<" ";
            curr=curr->next;
        }
}

node* reverseIterative(node* head)
{
    if(head==NULL || head->next ==NULL)
        return head;

    node* prev=NULL; node* curr=head;
    while(curr != NULL)
    {
        node* nextNode = curr->next;
        curr->next=prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

node* reverseRecurssive1(node* head, node* prev)
{
    if(head==NULL)
        return prev;

    node* nextNode=head->next;
    head->next=prev;
    prev=head;
    head=nextNode;
    return reverseRecurssive1(head, prev);
}

node* reverseRecurssive2(node* head)
{
    if(head==NULL || head->next == NULL)
        return head;

    node* rest_head = reverseRecurssive2(head->next);
    // node* rest_tail = head->next;----->
    // rest_tail->next = head;----------->  Also Correct
    // head = NULL;---------->

    head->next->next=head;
    head->next=NULL;

    return rest_head;
}

int main()
{
    node* head=NULL;
    head=insert(head, 10);
    head=insert(head,20);
    head=insert(head, 30);
    head=insert(head, 40);
    head= insert(head, 50);
    cout<<"Original Linked List: ";
    printLinkedList(head);
    cout<<endl;
    cout<<"Reversed Linded List  (Iterative): ";

    head=reverseIterative(head);
    printLinkedList(head);
    cout<<endl;
    
    cout<<"Reversed Linked List (Recurssive_1): ";
    head = reverseRecurssive1(head, NULL);
    printLinkedList(head);
    cout<<endl;

    cout<<"Reversed Linked List (Recurssive_2): ";
    head = reverseRecurssive1(head, NULL);
    printLinkedList(head);
    cout<<endl;
}