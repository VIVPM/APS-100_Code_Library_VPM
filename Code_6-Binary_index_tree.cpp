#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int a[N + 1];
    for(int i = 1;i <= N;i++)
    {
        cin >> a[i];
    }

    int binary[N + 1];
    memset(binary,0,sizeof(binary));
    for(int i = 1;i <= N;i++)
    {
        for(int j = i;j <= N;)
        {
            binary[j] += a[i];
            j += (j & (-j));
        }
    }

    for(int i = 1;i <= N;i++)
    {
        cout << binary[i] << " ";
    }

    cout << endl << binary[N] << endl;
}

/*
8
3 4 1 6 7 5 2 8
*/
