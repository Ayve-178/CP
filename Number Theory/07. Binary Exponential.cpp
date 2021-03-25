#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll binPow(ll a, ll b)
{
    ll res = 1;
    while(b>0)
    {
        if(b & 1)
            res = res*a;
        a = a*a;
        b >>= 1;
    }
    return res;
}

int main()
{
    cout<<binPow(3, 4)<<endl;
    cout<<binPow(3, 13)<<endl;
    cout<<binPow(5, 11)<<endl;
    cout<<binPow(4, 12)<<endl;
    return 0;
}
