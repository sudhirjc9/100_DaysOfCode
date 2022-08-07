#include<iostream>
using namespace std;

void sortcustum(int arr[], int n)
{
    int low=-1, high=n;
    for(int i=0; i<n; i++)
    {
        if(arr[i]==0)
            low++;
        else if(arr[i]==2)
            high--;
    }

    for(int i=0; i<n; i++)
        {
            if(i <=low)
                arr[i]=0;
            else if(i>=high)
                arr[i]=2;
            else
                arr[i]=1;
        }
}

void dutchAlgo(int arr[], int n)
{
    int low=0, mid=0, high=n-1;
    while(mid <=high)
    {
        if(arr[mid]==0)
            {
                swap(arr[low],arr[mid]);
                low++; mid++;
            }
        else if(arr[mid]==1)
            mid++;
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }

}

int main()
{
    int arr[]={0,1,2,1,2,0,0,0};
    //sortcustum(arr,8);
    dutchAlgo(arr,8);
    for(auto &x: arr)
        cout<<x<<" ";
}