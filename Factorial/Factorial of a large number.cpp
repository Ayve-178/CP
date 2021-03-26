#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define N 1000

int multiply(int n, int arr[], int len)
{
    int carry = 0, x;
    for(int i=0;i<len;i++)
    {
        x = arr[i]*n + carry;
        arr[i] = x%10;
        carry = x/10;
    }
    while(carry)
    {
        arr[len] = carry%10;
        carry = carry/10;
        len++;
    }
    return len;
}

void factorial(int n)
{
    int arr[N], len;
    arr[0] = 1;
    len = 1;
    for(int i=2;i<=n;i++)
        len = multiply(i, arr, len);
    for(int i=len-1;i>=0;i--)
        cout<<arr[i];
}

int main()
{
    int n;
    cin>>n;
    factorial(n);
    return 0;
}
