#include<iostream>
using namespace std;

    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        int curr_sum=0;
        int max_sum=arr[0];
        for(int i=0;i<n;i++)
            {
                if(curr_sum>=0)
                    curr_sum+=arr[i];
                else
                    curr_sum=arr[i];
                max_sum=max(max_sum,curr_sum);
            }
        return max_sum;
    }

int main()
{
    int arr[]={1,2,3,-2,5};
    cout<<"Max Sum:"<<maxSubarraySum(arr,5);

}