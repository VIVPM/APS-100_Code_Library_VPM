#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int a[N];
    for(int i = 0;i < N;i++)
    {
        cin >> a[i];
    }

    int tsum = 0,sum = 0;
    for(int i = 0;i < N;i++)
    {
        if(tsum + a[i] < 0)
        {
            tsum = 0;
        }

        else
        {
            tsum += a[i];
        }

        if(tsum > sum)
        {
            sum = tsum;
        }
    }

    cout << sum << endl;
}
