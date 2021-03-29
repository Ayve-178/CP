#include <bits/stdc++.h>

using namespace std;
#define ll long long

string decToBinary(int n, int b)
{
    string bin = "";
    for (int i=b-1;i>=0;i--)
    {
        int x = n >> i;
        if (x & 1)
            bin += "1";
        else
            bin += "0";
    }
    return bin;
}

int main()
{
    int n;
    cin>>n;
    int d = (log10(n)/log10(2)) + 1; ///The number of digits in binary format of n.
    cout<<d<<endl;
    cout<<decToBinary(n, d)<<endl;
    return 0;
}
