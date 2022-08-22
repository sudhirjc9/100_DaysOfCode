#include<bits/stdc++.h>
using namespace std;

int removeDublicates(int arr[], int size)
{
    int res=1;
    for(int i=1; i<size; i++)
        {
            if(arr[i]!=arr[res-1])
                {
                    arr[res]=arr[i];
                    res++;
                }
        }
    return res;
}

void moveZero_toEnd(int arr[], int n)
{
    int count=0;
    for(int i=0; i<n; i++)
        {
            if(arr[i]!=0){
                swap(arr[i],arr[count]);
                count++;
            }
        }

    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main()
{
    int arr[]={10,20,20,30,30,30,30};
    int size=removeDublicates(arr,7);
    for(int i=0; i<size; i++)
        cout<<arr[i]<<" ";

    int arr[]={1,0,2,0,3,0};
    moveZero_toEnd(arr,6);
}