#include <iostream>
#include<string>
using namespace std;
/***************Lcs*/////////////////////////////
int Lcs(string s,string p,int **arr)
{
    if(s.size()==0||p.size()==0)
        return 0;
    else
    {
        int n=s.size()-1,m=p.size()-1;
        if(arr[m][n]>0)
            return arr[m][n];
        if(s.back()==p.back())
            arr[m][n]=1+Lcs(s.substr(0,s.size()-1),p.substr(0,p.size()-1),arr);
        else
            arr[m][n]=max(Lcs(s.substr(0,s.size()),p.substr(0,p.size()-1),arr),Lcs(s.substr(0,s.size()-1),p.substr(0,p.size()),arr));
        return arr[m][n];
    }
}
int main()
{
    string s,p;
    cin>>s>>p;
    int n=s.size();
    int m=p.size();
    int** arr=new int*[n];
    for(int i=0;i<n;i++)
        arr[i]=new int[m]();
    cout<<Lcs(s,p,arr);
    for(int i=0;i<n;i++)
        delete[] arr[i];
    delete[] arr;
    return 0;
}
