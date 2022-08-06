#include<bits/stdc++.h>
#define MAX 10
using namespace std;

int queue_arr[MAX];
int rear=-1;
int front=-1;

void insert(int);
int del();
void display_queue();
int isEmpty();
int peek();
int isFull();

int main()
{
    int choice, item;
    while(1)
    {
        cout<<"1. Insert"<<endl;
        cout<<"2. Delete"<<endl;
        cout<<"3. Dispaly element at the front"<<endl;
        cout<<"4. Display all the elements of the queue"<<endl;
        cout<<"5. Quit"<<endl;
        cin>>choice;
        
        switch(choice)
        {
            case 1: cout<<"Input the element for adding in queue: "<<endl;
                    cin>>item;
                    insert(item);
                    break;

            case 2: 
                item=del();
                cout<<"Deleted element: "<<item<<endl;
                break;
            case 3:
                cout<<"Element at front is: "<<peek()<<endl;
                break;
            case 4: 
                display_queue();
                break;

            case 5:
                exit(1);
            default:
                cout<<"Wrong choice"<<endl;
            
        }
    }
}


    void insert(int item)
    {
        if(isFull())
        {
            cout<<"Queue overflow"<<endl;
            return;
        }
    if(front == -1)
        front=0;
    rear=rear+1;
    queue_arr[rear] = item;

    }

    int del()
    {
        int item;
        if(isEmpty())
            {
                cout<<"Queue underflow"<<endl;
                exit(1);
            }

        item = queue_arr[front];
        front = front+1;
        return item;

    }

    int peek()
    {
        if(isEmpty())
            {
                cout<<"Queue underflow"<<endl;
                    exit(1);
            }

        return queue_arr[front];

    }

    int isEmpty()
    {
        if(front== -1 || front == rear+1)
            return 1;
        else
            return 0;
    }

    int isFull()
    {
        if(rear == MAX -1)
            return 1;
        else
            return 0;
    }

    void display_queue()
    {
        int i;
        if(isEmpty())
        {
                cout<<"Queue underflow"<<endl;
                exit(1);
        }

        cout<<"Queue is: "<<endl;
        for(i= front; i<= rear; i++)
            cout<<queue_arr[i]<<" ";
        cout<<endl;
    }