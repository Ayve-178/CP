#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector <ll> primes;

void seive(ll mx)
{
    bool P[mx];
    memset(P, 0, sizeof P);
    P[1] = 1;
    for(ll i=3;i*i<=mx;i+=2)
    {
        if(!P[i])
        {
            for(ll j=i*i;j<=mx;j+=(2*i))
                P[j] = 1;
        }
    }
    primes.push_back(2);
    for(ll i=3;i<=mx;i+=2)
    {
        if(!P[i]) primes.push_back(i);
    }
}

void factFactorization(ll n)
{
    for(ll i=0;i<primes.size() && primes[i]<=n;i++)
    {
        ll x = n, freq = 0;
        while(x/primes[i])
        {
            freq += x/primes[i];
            x /= primes[i];
        }
        cout<<primes[i]<<"^"<<freq<<endl;
    }
}

int main()
{
    ll n;
    cin>>n;
    seive(n);
    factFactorization(n);
    cout<<endl;
    return 0;
}
