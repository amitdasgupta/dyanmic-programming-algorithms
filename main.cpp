#include <iostream>
#include<string>
using namespace std;
/***************Lcs*/////////////////////////////
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
int main()
{
    string s,p;
    cin>>s>>p;
    cout<<Lcs(s,p);
    return 0;
}
