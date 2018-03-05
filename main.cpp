#include <iostream>
#include<string>
#include<algorithm>
#include<unordered_map>
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
/**************
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
}*///////////
/***********catalns numbers code*////////
int catalansNumbers(long long n)
{
    long long *array=new long long[n+1];
    array[1]=1;
    array[0]=1;
    for(long long i=1;i<=n;i++)
    {
        array[i]=array[i-1]*array[n-i];
        cout<<array[i]<<endl;
    }
    long long res=array[n];
    delete[] array;
    return res;
}
/******************matrix chain multiplication code*/////////
int matrixChainMultiplication(int *array,int start,int last)
{
    if(start==last)
        return 0;
    else
    {
        int res=INT_MAX,temp;
        for(int i=start;i<last;i++)
        {
            temp=matrixChainMultiplication(array,start,i)+
                 matrixChainMultiplication(array,i+1,last)+
                 array[start-1]*array[i]*array[last];
            if(temp<res)
                res=temp;
        }
        return res;
    }
}
/************code for matrix chain multiplication using dp*////////////
int matrixChainMultiplicationDp(int *array,int n)
{
    int arr[n+1][n+1];
    for(int i=1;i<=n;i++)
        arr[i][i]=0;
    for(int L=1;L<n;L++)
    {
        for(int i=1;i<=n-L;i++)
        {
            int j=i+L,temp;
            cout<<i<<" "<<j<<endl;
            arr[i][j]=INT_MAX;
            for(int k=i;k<j;k++)
            {
             temp=arr[i][k]+arr[k+1][j]+array[i-1]*array[k]*array[j];
             if(temp<arr[i][j])
                    arr[i][j]=temp;
            }
        }
    }
    return arr[1][n];
}
/*************basic object declaration*////////////
struct Object{
int weight;
int value;
};
/************Integer knapsack problem*//////////////
int integerKnapsack(Object* array,int capacity,int i)
{
    if(capacity==0||i<0)
        return 0;
    else
    {
        if(array[i].weight>capacity)
            return integerKnapsack(array,capacity,i-1);
        else
            return max(array[i].value+integerKnapsack(array,capacity-array[i].weight,i),integerKnapsack(array,capacity,i-1));
    }
}
/************Integer knapsack problem*//////////////
int integerKnapsackDp(Object* array,int capacity,int n)
{
    int result[n][capacity+1];
    for(int i=0;i<n;i++)
        result[i][0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=capacity;j++)
        {
            if(array[i].weight>j)
                result[i][j]=result[i-1][j];
            else
                result[i][j]=max(array[i].value+result[i][j-array[i].weight],result[i-1][j]);
        }
    }
    return result[n-1][capacity];
}
/****************fractional knapsack problem*/////////////////
int fractionalKnapsackDp(Object* array,int capacity,int n)
{
    int result[n][capacity+1];
    for(int i=0;i<n;i++)
        result[i][0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=capacity;j++)
        {
            if(array[i].weight>j)
                result[i][j]=result[i-1][j];
            else
                result[i][j]=max(array[i].value+result[i-1][j-array[i].weight],result[i-1][j]);
           // cout<<result[i][j]<<endl;
        }
    }
    return result[n-1][capacity];
}
/***********making coin change problem*//////////
int coinChange(int *array,int start,int last,int value)
{
    if(start>last||value<0)
        return 0;
    if(value==0)
        return 1;
    return coinChange(array,start,last,value-array[last])+coinChange(array,start,last-1,value);
}
/*****coin change using dp*//////
int coinChangeDp(int *array,int n,int total)
{
    int **arr=new int*[n];
    for(int i=0;i<n;i++)
        arr[i]=new int[total+1];
    for(int i=0;i<n;i++)
        arr[i][0]=0;
    for(int j=1;j<=total;j++)
    {
     arr[0][j]=j;
    }
    for(int i=1;i<n;i++)
        for(int j=1;j<=total;j++)
    {
        if(array[i]>j)
            arr[i][j]=arr[i-1][j];
        else
            arr[i][j]=min(arr[i-1][j],1+arr[i][j-array[i]]);
            cout<<arr[i][j]<<endl;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=total;j++)
            cout<<arr[i][j]<< " ";
        cout<<endl;
    }
    return arr[n-1][total];
}
/************number of ways coin can be changed*///////
int numberOfWays(int *array,int n,int total)
{
    int arr[n][total+1];
    for(int i=0;i<n;i++)
        arr[i][0]=1;
    for(int i=1;i<=total;i++)
        arr[0][i]=1;
    for(int i=1;i<n;i++)
     {
            for(int j=1;j<=total;j++)
    {
        if(array[i]>j)
            arr[i][j]=arr[i-1][j];
        else
            arr[i][j]=arr[i-1][j]+arr[i][j-array[i]];
       // cout<<arr[i][j]<<" ";
    }
    //cout<<endl;
     }
    return arr[n-1][total];
}
/*******brute force code for LIS*///////
int lisSubsequence(int *array,int n,int &last_element)
{
    if(n==1)
        {
            last_element=0;
            return 1;
        }
    else
    {
        int m=n-1,maxi=INT_MIN;
        for(int i=0;i<m;i++)
        {
            maxi=max(maxi,lisSubsequence(array,i+1,last_element));
        }
        if(array[m]>array[last_element])
        {
            last_element=m;
            return maxi+1;
        }
        else
            return maxi;
    }
}
int main() {
    int n;
    cin>>n;
    int *array=new int[n];
    for(int i=0;i<n;i++)
        cin>>array[i];
    int a;
    cout<<lisSubsequence(array,n,a);
    delete[] array;
}
