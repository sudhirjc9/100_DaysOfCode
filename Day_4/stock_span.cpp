#include<iostream>
#include<stack>
using namespace std;

void stock_span(int arr[], int n)
{
    stack<int>st;

    st.push(0);
    cout<<1<<" ";
    for(int i=1; i<n; i++)
    {
        while(st.empty()==false && arr[st.top()]< arr[i])
            st.pop();
        
        int span = st.empty()==true? i+1:i-st.top();
        cout<<span<<" ";
        st.push(i);
    }
}

/*

Other probelms based on this stock span problem are:
1. Previous greater element
2. Next greater element

*/

int main()
{
    int arr[]={60,10,20,15,35,60};

    stock_span(arr,6);
}