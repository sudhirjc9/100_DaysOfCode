#include<bits/stdc++.h>
using namespace std;

void next_pre_smaller_ele(int arr[], int n)
{
    int prev[n]={0};
    int next[n]={0};
    stack<int>st;
    stack<int>st1;

    //cout<<"Previous Smaller: ";
    st.push(0);
    prev[0]=-1;
    next[n-1]=-1;
    //cout<<-1<<" ";
    for( int i=1; i<n; i++)
    {
        while(st.empty()==false && arr[st.top()]>=arr[i])
            st.pop();

        int prev_smaller = st.empty()==true?-1:st.top();
        //cout<<prev_smaller<<" ";
        prev[i]=prev_smaller;
        st.push(i); 
    }

    cout<<endl<<"Next Smaller: ";
    st1.push(n-1);
    //cout<<-1<<" ";
    for(int i=n-2; i>=0; i--)
    {
        while(st1.empty()==false && arr[st1.top()]>arr[i])
            st1.pop();

        int next_smaller = st1.empty()==true?7:st1.top();
        //cout<<next_smaller<<" ";
        next[i]=next_smaller;
        st1.push(i);
    }
cout<<"Previous Smaller: ";
    for(auto &x: prev)
        cout<<x<<" ";
    cout<<endl;
cout<<"Next Smaller: ";
    for(auto &x: next)
        cout<<x<<" ";

    int res=0;
    int curr=0;
    for(int i=0; i<n; i++)
        {
            curr=arr[i];
            curr+=(i-prev[i]-1)*arr[i];
            curr+=(next[i]-i-1)*arr[i];
            res=max(res,curr);
        }

    cout<<endl<<"Max Area: "<<res<<" ";
}

int main()
{
   // int arr[]={60,10,20,15,35,60};
    int arr[]={6, 2, 5, 4, 1, 5, 6};
    next_pre_smaller_ele(arr,7);
}