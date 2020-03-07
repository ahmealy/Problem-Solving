#include<algorithm>
#include<stdio.h>
#include<iostream>
#include <climits>
#include<vector>
#include<unordered_map>
#include <bitset>
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<string> dic;
string rule;

vector<string> lAns;

void solve(int sId)
{
    if(sId == rule.length())
    {
        for(int i = 0; i < lAns.size(); i++)
        {
            cout << lAns[i];
        }
        cout << endl;
    }
    else
    {
        if(rule[sId] == '#')
        {
            for(int i = 0; i < dic.size(); i++)
            {
                lAns.push_back(dic[i]);
                solve(sId+1);
                lAns.pop_back();
            }
        }
        if(rule[sId] == '0')
        {
            for(int i = 0; i < 10; i++)
            {
                lAns.push_back(to_string(i)); // or lAns[sId] = dic[i]; and remove pop
                solve(sId+1);
                lAns.pop_back();
            }
        }

    }


}

int main()
{
    while(cin >> n)
    {
        printf("--\n");
        dic.clear();
        dic.resize(n);
        for(int i = 0; i < n; i++)
        {
            cin >> dic[i];
        }
        scanf("%d", &m);
        for(int i = 0; i < m; i++)
        {
            cin >> rule;
            solve(0);
        }
    }
}
