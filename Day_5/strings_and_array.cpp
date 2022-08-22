#include<iostream>
#include<string>
using namespace std;

int main()
{
    //char str[] = "gfg";

    // string str;
    // getline(cin, str);

    // cout<<sizeof(str);

//**********Subsequence Problem.
    // string s1 = "geeksforgeeks";
    // string s2 = "grges";

    // int i=0, j=0;
    // for( i=0; i< s1.length(); i++)
    // {
    //     if(s1[i]==s2[j])
        
    //         j++;
    //  else
    //     i++;
    // }

    // if(j==s2.length())
    //     cout<<"s2 is subsequence";
    // else
    //     cout<<"Not subsequence";

//***************Leftmost repeating charecter
 string str1="cabbadc";
int index=1000;
int arr[26];
for(int i=0; i<26; i++)
    arr[i]=1000;
for(int i=0; i<str1.length(); i++)
{   
    if(arr[str1[i]-'a'] !=1000)
            index=min(index, arr[str1[i]-'a']);
    arr[str1[i]-'a'] = i;
}
        cout<<index<<" ";




}