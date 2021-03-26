#include <bits/stdc++.h>

using namespace std;
#define ll long long

int LIS(int arr[], int n)
{
    int seq[n];
    seq[0] = 1;
    for(int i=1;i<n;i++)
    {
        seq[i] = 1;
        for(int j=0;j<i;j++)
        {
            if(arr[i] > arr[j])
            {
                if(seq[i] < seq[j]+1)
                {
                    seq[i] = seq[j] + 1;
                }
            }
        }
    }
    sort(seq, seq+n);
    return seq[n-1];
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<LIS(arr, n)<<endl;
    return 0;
}
