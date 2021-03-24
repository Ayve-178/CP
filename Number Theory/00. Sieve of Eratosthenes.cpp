#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define l long
#define pi acos(-1)

#define N 1000010
bool P[N];
vector <ll> primes;
ll lenP;

void seive()
{
    memset(P, 0, sizeof(P));
    P[1] = 1;
    for(ll i=3;i*i<N;i+=2)
    {
        if(P[i]==0)
        {
            for(ll j=i*i;j<N;j+=(2*i))
            {
                P[j] = 1;
            }
        }
    }
    primes.push_back(2);
    for(ll i=3;i<N;i+=2)
    {
        if(P[i]==0)
            primes.push_back(i);
    }
    lenP = primes.size();
}


int main()
{
    seive();

    ///Print first 100 prime numbers
    cout<<"First 100 prime numbers are: "<<endl;
    for(int i=0;i<100;i++)
        cout<<primes[i]<< " ";
    cout<<endl;

    ///Check if x is prime or not
    int x = 15;
    ll lb = lower_bound(primes.begin(), primes.end(), x) - primes.begin();
    if(primes[lb] == x)
        cout<<x<< " is a prime number"<<endl;
    else
        cout<<x<< " is not a prime number"<<endl;

    x = 5;
    lb = lower_bound(primes.begin(), primes.end(), x) - primes.begin();
    if(primes[lb] == x)
        cout<<x<< " is a prime number"<<endl;
    else
        cout<<x<< " is not a prime number"<<endl;

    x = 19;
    lb = lower_bound(primes.begin(), primes.end(), x) - primes.begin();
    if(primes[lb] == x)
        cout<<x<< " is a prime number"<<endl;
    else
        cout<<x<< " is not a prime number"<<endl;

    x = 40;
    lb = lower_bound(primes.begin(), primes.end(), x) - primes.begin();
    if(primes[lb] == x)
        cout<<x<< " is a prime number"<<endl;
    else
        cout<<x<< " is not a prime number"<<endl;
}
