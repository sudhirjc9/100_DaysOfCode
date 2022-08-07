#include<iostream>
using namespace std;

void reverseArray(int arr[], int n)
{
    int low=0, high = n-1;

    while(low <= high)
    {
        swap(arr[low],arr[high]);
        low++;
        high--;
    }
}

struct pairMinMax
{
    int min;
    int max;
};


pairMinMax minMax(int arr[], int n)
{
    pairMinMax res;
    if(n==1)
        {
            res.max=arr[0];
            res.min=arr[0];
            return res;
        }

    res.max=max(arr[0],arr[1]);
    res.min=min(arr[0],arr[1]);

    for(int i=2; i<n; i++)
        {
            res.max=max(res.max,arr[i]);
            res.min=min(res.min,arr[i]);
        }

    return res;
}


pairMinMax minMaxRecurssive(int arr[], int low, int high)
{

    pairMinMax res, mml, mmr;

    if(low==high)
        {
            res.max=arr[low];
            res.min=arr[low];
            return res;
        }

    if(high==low+1)
    {
        if(arr[low]>arr[high])
        {
            res.max=arr[low];
            res.min=arr[high];
        }

        else{
            res.max=arr[high];
            res.min=arr[low];
        }

        return res;
    }

    int mid = (low + high)/2;
    mml=minMaxRecurssive(arr, low, mid);
    mmr=minMaxRecurssive(arr,mid+1,high);

    if(mml.min < mmr.min)
        res.min = mml.min;
    else
        res.min=mmr.min;

    if(mml.max < mmr.max)
        res.max = mmr.max;
    else
        res.max=mml.max;

    return res;

}


int main()
{
    int arr[]={1,2,3,4,6};
    reverseArray(arr,5);

    for(auto &x: arr)
        cout<<x<<" ";
    cout<<endl;

    pairMinMax p=minMax(arr, 5);

    cout<<"Max element: "<<p.max<<endl;
    cout<<"Min element: "<<p.min<<endl;

    pairMinMax pr=minMaxRecurssive(arr, 0, 4);

    cout<<"Max element: "<<pr.max<<endl;
    cout<<"Min element: "<<pr.min<<endl;

}