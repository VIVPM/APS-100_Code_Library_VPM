#include<iostream>
using namespace std;

int subset_sum(int n,int *a,int sum)
{
    int ss[n + 1][sum + 1];
    for(int i = 1; i < sum + 1; i++)
    {
        ss[0][i] = 0;
    }

    for(int j = 0; j <  n + 1; j++)
    {
        ss[j][0] = 1;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= sum; j++)
        {
            if(ss[i - 1][j] == 1)
            {
                ss[i][j] = 1;
            }

            else if(a[i - 1] > j)
                ss[i][j] = 0;
            else
                ss[i][j] = ss[i - 1][j - a[i - 1]];

        }
    }

    for(int i = 0;i < n + 1;i++){
        for(int j = 0;j < sum + 1;j++){
            cout << ss[i][j] << " ";
        }

        cout << endl;
    }

    return ss[n][sum];

}

int main()
{
    int n,sum;
    cin >> n >> sum;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << subset_sum(n,a,sum) << endl;
}
