#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define mx 32000 //sqrt(10^9)
vector <ll> primes;

void seive()
{
    bool P[mx];
    memset(P, 0, sizeof(P));
    P[1] = 1;
    for(ll i=3;i*i<mx;i+=2)
    {
        if(P[i]==0)
        {
            for(ll j=i*i;j<=mx;j+=(2*i))
                P[j] = 1;
        }
    }
    primes.push_back(2);
    for(ll i=3;i<=mx;i+=2)
        primes.push_back(i);
}

void segmentedSeive(ll l, ll r)
{
    bool isPrime[r-l+1];
    memset(isPrime, 0, sizeof(isPrime));
    for(ll i=0;primes[i]*primes[i]<=r;i++)
    {
        ll curPrime = primes[i];
        ll base = (l/curPrime)*curPrime;
        if(base<l) base+=curPrime;
        for(ll j=base;j<=r;j+=curPrime)
        {
            isPrime[j-l] = 1;
        }
        if(base == curPrime) isPrime[base-l] = 0;
    }
    for(ll i=0;i<r-l+1;i++)
    {
        if(isPrime[i]==0) cout<<i+l<< " ";
    }
}

int main()
{
    seive();
    /// Print prime numbers from a to b
    ll a = 200, b = 250;
    segmentedSeive(a,b);
    return 0;
}
