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
/***************code to find maximum sum of contigous elements
int maxContinousSum(int *array,int n)
{
    int max_sum=array[0],max_ending_sum=array[0];
    for(int i=1;i<n;i++)
    {
        max_ending_sum=max(array[i],max_ending_sum+array[i]);
        max_sum=max(max_sum,max_ending_sum);
    }
    return max_sum;
}*////////
/********maximum sum of non contigous elements in array*/////////
/****************************************************************
int maxNonContigous(int *array,int n)
{
    int incSum=array[0],excSum=0,prev;
    for(int i=1;i<n;i++)
    {
        prev=incSum;
        incSum=excSum+array[i];
        excSum=max(excSum,prev);
    }
    return max(incSum,excSum);
}
int main()
{
    int n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int *array=new int[n];
        for(int i=0;i<n;i++)
        cin>>array[i];
        cout<<maxNonContigous(array,n)<<endl;
        delete[] array;
    }
    return 0;
}*//////////////
int catalanNumber(int n,long long * &array)
{
    if(n==1||n==0)
        return 1;
    else
    {
       long long res=0,left,right;
        for(int i=1;i<=n;i++)
        {
            if(!array[i-1])
               {
                   left=catalanNumber(i-1,array);
                   array[i-1]=left;
               }
            else
                left=array[i-1];
            if(!array[n-i])
                {
                    right=catalanNumber(n-i,array);
                    array[n-i]=right;
                }
            else
                right=array[n-i];
            res+=left*right;
        }
        return res;
    }
}
int main() {
    long long t=1,n,*array;
    while(t)
    {
        cin>>t>>n;
        array=new long long[n]();
        cout<<catalanNumber(n,array)<<endl;
        delete[] array;
    }
}
