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

void primeFactorization(ll n)
{
    primeFactors.clear();
    for(ll i=0;i<primes.size() && primes[i]*primes[i]<=n;i++)
    {
        if(n%primes[i]==0)
        {
            while(n%primes[i]==0)
            {
                n/=primes[i];
                primeFactors.push_back(primes[i]);
            }
        }
    }
    if(n>1)
        primeFactors.push_back(n);
    for(ll i=0;i<primeFactors.size();i++)
    {
        cout<<primeFactors[i]<< " ";
    }
    cout<<endl;
}


int main()
{
    seive(100010);     /// To factorize N, we need to generate primes up to sqrt(N) only.
    int t, n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<"Prime Factors of "<<n<< " are: "<<endl;
        primeFactorization(n);
        cout<<endl;
    }
    return 0;
}
