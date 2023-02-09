#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    vector<vector<int>>LCS(s1.size() + 1,vector<int>(s2.size() + 1));
    string  t = "";
    for(int i = 1;i <= s1.size();i++){
        for(int j = 1;j <= s2.size();j++){
            if(i == 0 || j == 0){
                LCS[i][j] = 0;
            }

            else if(s1[i - 1] == s2[j - 1]){
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            }

            else{
                LCS[i][j] = max(LCS[i - 1][j],LCS[i][j - 1]);
            }

        }
    }

    cout << LCS[s1.size()][s2.size()] << " " << t;

}
