#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    int a, b, gcd, lcm;
    a = 10, b = 20;
    gcd = __gcd(a,b);
    lcm = (a/gcd) * b;          /// gcd(a,b) * lcm(a,b) = a*b
    cout<<gcd<< " " <<lcm<<endl;

    a = 20, b = 40;
    gcd = __gcd(a,b);
    lcm = (a/gcd) * b;
    cout<<gcd<< " " <<lcm<<endl;

    a = 3, b = 7;
    gcd = __gcd(a,b);
    lcm = (a/gcd) * b;
    cout<<gcd<< " " <<lcm<<endl;

    a = 3, b = 21;
    gcd = __gcd(a,b);
    lcm = (a/gcd) * b;
    cout<<gcd<< " " <<lcm<<endl;
    return 0;
}
