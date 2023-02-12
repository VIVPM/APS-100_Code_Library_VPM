#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


int Longest_Common_Subsequence(string s1,string s2)
{
    vector<vector<int>>LCS(s1.size() + 1,vector<int>(s2.size() + 1));
    string  t = "";
    for(int i = 1; i <= s1.size(); i++)
    {
        for(int j = 1; j <= s2.size(); j++)
        {
            if(i == 0 || j == 0)
            {
                LCS[i][j] = 0;
            }

            else if(s1[i - 1] == s2[j - 1])
            {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            }

            else
            {
                LCS[i][j] = max(LCS[i - 1][j],LCS[i][j - 1]);
            }

        }
    }

    int i=s1.size();
    int j=s2.size();
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            t+=s1[i-1];
            i--;
            j--;
        }
        else if(LCS[i-1][j]>LCS[i][j-1])
        {
            i=i-1;
        }
        else
        {
            j=j-1;
        }
    }

    reverse(t.begin(),t.end());
    return LCS[s1.size()][s2.size()];

}

int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    int lcs = Longest_Common_Subsequence(s1,s2);
    cout << lcs << endl;
}
