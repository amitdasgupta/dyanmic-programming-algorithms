#include <iostream>
#include<string>
using namespace std;
/***************Lcs
int Lcs(string s,string p)
{
    int n=s.size();
    int m=p.size();
    int arr[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0||j==0)
                arr[i][j]=0;
            else
                if(s[i-1]==p[j-1])
                arr[i][j]=1+arr[i-1][j-1];
            else
                arr[i][j]=max(arr[i][j-1],arr[i-1][j]);
        }
    }
    return arr[n][m];
}
*/////////////////////////////
int maxContinousSum(int *array,int n)
{
    int max_sum=array[0],max_ending_sum=array[0];
    for(int i=1;i<n;i++)
    {
        max_ending_sum=max(array[i],max_ending_sum+array[i]);
        max_sum=max(max_sum,max_ending_sum);
    }
    return max_sum;
}
int main()
{
    int n;
    int *array=new int[n];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>array[i];
    cout<<maxContinousSum(array,n);
    delete[] array;
    return 0;
}
