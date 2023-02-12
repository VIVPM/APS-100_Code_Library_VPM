#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

const int n = 3;

int Assignment(int a[][n])
{
    int f = pow(2,n);
    //cout << f << endl;
    int dp[f];
    for(int i = 0;i < f;i++){
        if(i == 0){
            dp[i] = 0;
        }

        else{
            dp[i] = 999999;
        }
    }
    for(int mask = 0; mask < f; mask++)
    {
        int x = 0,mask1 = mask;
        while(mask1)
        {
            x += mask1 & 1;
            mask1 >>= 1;
        }

        //cout << x << endl;
        for(int j = 0; j < n; j++)
        {
            if((mask & (1 << j)) == 0)
            {
                dp[mask | (1 << j)] = min(dp[mask | (1 << j)], (dp[mask] + a[x][j]));
            }
        }
    }

    return dp[f - 1];
}

int main()
{
    //cin >> n;
    int optimal[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> optimal[i][j];
        }
    }

    int dp = Assignment(optimal);
    cout << dp << endl;
}

/*
3 2 7
5 1 3
2 7 2
*/

