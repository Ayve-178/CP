#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector <ll> primes, primeFactors;

void seive(ll mx)
{
    bool P[mx];
    memset(P, 0, sizeof(P));
    P[1] = 1;
    for(ll i=3;i*i<=mx;i+=2)
    {
        if(!P[i])
        {
            for(ll j=i*i;j<=mx;j+=(2*i))
            {
                P[j] = 1;
            }
        }
    }
    primes.push_back(2);
    for(ll i=3;i<mx;i+=2)
    {
        if(!P[i]) primes.push_back(i);
    }
}

ll NOD(ll n)
{
    ll divisor = 1;
    for(ll i=0;i<primes.size() && primes[i]*primes[i]<=n;i++)
    {
        if(n%primes[i]==0)
        {
            ll cnt = 0;
            while(n%primes[i]==0)
            {
                n /= primes[i];
                cnt++;
            }
            cnt++;
            divisor *= cnt;
        }
    }
    if(n>1) divisor*=2;
    return divisor;
}

int main()
{
    seive(1000);
    ll t, n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll res = NOD(n);
        cout<<res<<endl;
    }
    return 0;
}
