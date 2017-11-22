#include <iostream>

using namespace std;
/***********************0/1 knapack problem brute force method*///////////////////
int knapsackProblem(int *arrweight,int *arrval,int n,int totalwieght)
{
    if(n==0||totalwieght==0)
        return 0;
    else
        if(arrweight[n-1]>totalwieght)
        return knapsackProblem(arrweight,arrval,n-1,totalwieght);
    else
        return max(knapsackProblem(arrweight,arrval,n-1,totalwieght),arrval[n-1]+knapsackProblem(arrweight,arrval,n-1,totalwieght-arrweight[n-1]));
}

int main()
{
    int *arrval,*arrweight,totalweight,n;
    cout<<"enter number of weights and total weight"<<endl;
    cin>>n>>totalweight;
    arrval=new int[n];
    arrweight=new int[n];
    cout<<"enter weights and values "<<endl;
    for(int i=0;i<n;i++)
        cin>>arrweight[i]>>arrval[i];
    cout<<knapsackProblem(arrweight,arrval,n,totalweight);
    delete[] arrval;
    delete[] arrweight;
    return 0;
}
