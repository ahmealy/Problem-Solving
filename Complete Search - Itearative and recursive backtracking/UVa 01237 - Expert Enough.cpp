// UVA 1237

#include<algorithm>
#include<stdio.h>
#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int D;
        unordered_map<string,pair<int,int>> lDb;
        scanf("%d", &D);
        for(int i = 0; i < D; i++)
        {
            string name;
            int low, high;
            cin >> name >> low >> high;
            lDb[name] = make_pair(low, high);
        }

        int Q;
        scanf("%d", &Q);
        for(int i = 0; i < Q; i++)
        {
            int price, matches = 0;
            string car;
            cin >> price;

            for (auto entry : lDb)
            {
                if(price >=  entry.second.first && price <=  entry.second.second)
                {
                    car = entry.first;
                    matches++;
                }
                if(matches > 1)
                {
                    break;
                }
            }
            if(matches == 1)    cout << car << endl;
            else                cout << "UNDETERMINED" << endl;
        }

        if(T)   cout << endl;
    }

    return 0;
}
