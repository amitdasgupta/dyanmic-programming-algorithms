#include <iostream>

using namespace std;
/***********************0/1 knapack problem using dynamic programming
int knapsackProblem(int *arrweight,int *arrval,int n,int totalwieght,int** result)
{
    if(n==0||totalwieght==0)
        return 0;
    else
        {
            if(result[n][totalwieght]>0)
                return result[n][totalwieght];
            if(arrweight[n-1]>totalwieght)
        {   result[n][totalwieght]=knapsackProblem(arrweight,arrval,n-1,totalwieght,result);
            return result[n-1][totalwieght];
        }
    else
        {
            result[n][totalwieght]=max(knapsackProblem(arrweight,arrval,n-1,totalwieght,result),arrval[n-1]+knapsackProblem(arrweight,arrval,n-1,totalwieght-arrweight[n-1],result));
            return result[n][totalwieght];

        }
        }
}
*///////////////////
int matrixChainMultiplication(int* arr,int start,int last)
{
    int res=0,mini;
    if(start==last)
        return 0;
    else
    {
        int mini=INT_MAX;
        for(int i=start;i<last;i++)
        {
            res=matrixChainMultiplication(arr,start,i)+matrixChainMultiplication(arr,i+1,last)+arr[start]*arr[last+1]*arr[i+1];
            if(res<mini)
                mini=res;
        }
        return res;
    }
}
int main()
{   /***********knapsack code
    int *arrval,*arrweight,totalweight,n,**result;
    cout<<"enter number of weights and total weight"<<endl;
    cin>>n>>totalweight;
    arrval=new int[n];
    arrweight=new int[n];
    result=new int*[n+1];
    for(int i=0;i<=n;i++)
        result[i]=new int[totalweight+1]();
    cout<<"enter weights and values "<<endl;
    for(int i=0;i<n;i++)
        cin>>arrweight[i]>>arrval[i];
    cout<<knapsackProblem(arrweight,arrval,n,totalweight,result);
    delete[] arrval;
    delete[] arrweight;
    for(int i=0;i<=n;i++)
        delete[] result[i];
    delete[] result;*/
    int *arr,n;
    cin>>n;
    arr=new int[n+1];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<matrixChainMultiplication(arr,0,n-1);
    return 0;
}
