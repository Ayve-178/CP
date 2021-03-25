#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll bigMod(ll a, ll b, ll m)
{
    ll res = 1;
    while(b>0)
    {
        if(b & 1)
            res = ((res%m) * (a%m)) % m;
        a = ((a%m) * (a%m)) % m;
        b >>= 1;
    }
    return res;
}

ll modInverse(ll a, ll z)
{
    return bigMod(a, z-2, z);
}

int main()
{
    cout<<bigMod(3, 18132, 17)<<endl;
    cout<<bigMod(17, 1765, 3)<<endl;
    cout<<bigMod(2374859, 3029382, 36123)<<endl;
    return 0;
}
