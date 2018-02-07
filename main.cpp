#include <iostream>
#include<string>
using namespace std;
/***************Lcs*/////////////////////////////
int Lcs(string s,string p)
{
    if(s.size()==0||p.size()==0)
        return 0;
    else
    {
        if(s.back()==p.back())
            return 1+Lcs(s.substr(0,s.size()-1),p.substr(0,p.size()-1));
        else
            return max(Lcs(s.substr(0,s.size()),p.substr(0,p.size()-1)),Lcs(s.substr(0,s.size()-1),p.substr(0,p.size())));
    }
}
int main()
{
    string s,p;
    cin>>s>>p;
    cout<<Lcs(s,p);
    return 0;
}
