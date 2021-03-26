#include <bits/stdc++.h>

using namespace std;
#define ll long long

int LCS(string x, string y, int m, int n)
{
    int L[m+1][n+1];
    int i, j;
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0 || j==0)
                L[i][j] = 0;
            else if(x[i-1] == y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    return L[m][n];
}

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    int l1 = s1.length();
    int l2 = s2.length();
    cout<<LCS(s1, s2, l1, l2)<<endl;
    return 0;
}
