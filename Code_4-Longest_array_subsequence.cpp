#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int LIS[N],a[N];
    memset(LIS,0,sizeof(LIS));
    for(int i = 0;i < N;i++){
        cin >> a[i];
    }

    int prev = 1;
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < i;j++)
        {
            if(a[i] > a[j] && LIS[j] + 1 > LIS[i])
            {
                LIS[i] = LIS[j] + 1;
                if(prev < LIS[i])
                {
                    prev = LIS[i];
                }
            }
        }
    }

    cout << prev + 1<< endl;
}
