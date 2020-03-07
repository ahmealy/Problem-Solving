#include<algorithm>
#include<stdio.h>
#include<iostream>
#include <climits>
#include<vector>
#include<unordered_map>
#include <bitset>
#include <bits/stdc++.h>

using namespace std;

int n, v, num_paths;
vector<int> result(100);
set< vector<int> > resultSet;

void getWalksDFS(int start, vector<vector<int>>& graph, vector<bool>& visited, int xn)
{
    //cout << "start " << start << " xn " << xn << endl;
    result[xn] = start+1;
    if(xn == n)
    {
        /*for(int i = 0; i <= n; i++)
            cout << result[i] << " ";
        cout << endl;*/
        num_paths ++;
        printf("(");
        for(int i = 0; i < n + 1; i++)
        {
            printf("%d", result[i]);
            if(i < n)
                printf(",");
        }
        printf(")\n");
        return;
        //resultSet.insert(result);
    }
    else
    {
        //cout << "push_back " << start +1 << endl;
        // Set current node as visited

        // For every node of the graph
        for (int i = 0; i < v; i++)
        {

            // If some node is adjacent to the current node
            // and it has not already been visited
            if (graph[start][i] == 1 && (!visited[i]))
            {
                //cout << "before rec start " << start  << " xn " << xn << endl;
                visited[i] = true;
                //result.push_back(start+1);
                getWalksDFS(i, graph, visited, xn +1);
                //cout << "after rec start " << start  << " xn " << xn << endl;
                visited[i] = false;
                //result.pop_back();
            }
        }
    }

}

int main()
{
    while(1)
    {
        cin >> v >> n;
        vector<vector<int>> graph(v, vector<int>(v));
        vector<bool> visited(v, false);
        resultSet.clear();
        result.clear();
        for(int i = 0; i < v; i++)
        {
            for(int j = 0; j < v; j++)
            {
                cin >> graph[i][j];
            }
        }
        visited[0] = true;
        num_paths = 0;
        getWalksDFS(0, graph, visited, 0);
        if(num_paths == 0) printf("no walk of length %d\n", n);
        if(scanf("%d", &v) == -1) break;
        else printf("\n");
        /*for (vector<int> v: resultSet)
        {
            cout << "(";
            for(int i = 0; i <= n; i++)
            {
                cout << v[i];
                if(i != n)  cout << ",";
                else        cout << ")" << endl;
            }
        }*/


    }
}
